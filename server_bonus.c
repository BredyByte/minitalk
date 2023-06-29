/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:36:40 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/29 18:46:09 by dbredykh         ###   ########.fr       */
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
		ft_putchar(c);
		i = 0;
		c = 0;
		kill(sig_info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SIGINT;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
