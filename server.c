/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:36:40 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/29 18:22:59 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	ft_handler(int sig_num)
{
	static int	i;
	static int	c;

	if (sig_num == SIGUSR1)
		c |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
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
	sa.sa_handler = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SIGINT;
	// предотвращает ошибку когда вызываешь несколько раз много букв и вылазит ошибка
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	// предотвращает ошибку которая появляется когда достаем sigaction из цикла.
	while (1)
	{
		pause();
	}
	return (0);
}
