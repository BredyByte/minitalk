/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:36:16 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/27 18:05:37 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	ft_confirm(int signal)
{
	(void) signal;
	ft_putstr_fd("\nRESP\n", 1);
}

void	ft_send_byte(int pid, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if ((c & (0x01 << b)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		b++;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error!");
		return (1);
	}
	sa.sa_handler = ft_confirm;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	while (argv[2][i])
	{
		ft_send_byte(pid, argv[2][i]);
		i++;
	}
	ft_send_byte(pid, '\0');
	return (0);
}
