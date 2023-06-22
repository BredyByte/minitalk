/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:36:16 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/22 17:55:32 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	handler(int sig)
{
	(void) sig;
	ft_printf("\n ACK\n");
	exit(0);
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
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_send_byte(pid, argv[2][i]);
			i++;
		}
		ft_send_byte(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		return (1);
	}
	return (0);
}
