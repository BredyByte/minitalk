/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:36:40 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/27 18:06:08 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	ft_handler(int sig_num, siginfo_t *sig_info, void *context)
{
	static int	i;
	static int	c;

	(void) context;
	if (sig_num == SIGUSR1)
		c |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			ft_printf("\n");
			kill(sig_info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_sigaction = ft_handler;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
