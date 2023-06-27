/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus_testfile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:36:16 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/27 18:08:21 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	ft_confirm(int signal)
{
	(void)signal;
	ft_putstr_fd("\nRESP\n", 1);
}

void	ft_send_packet(int pid, char *packet)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((packet[i] & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		i++;
	}
}

void	ft_send_message(int pid, char *message)
{
	int		packet_count;
	int		message_length;
	int		i;
	char	packet[8];

	packet_count = 0;
	message_length = ft_strlen(message);
	while (packet_count * 8 < message_length)
	{
		i = 0;
		ft_memset(packet, 0, sizeof(packet));
		while (i < 8 && (packet_count * 8 + i) < message_length)
		{
			packet[i] = message[packet_count * 8 + i];
			i++;
		}
		ft_send_packet(pid, packet);
		packet_count++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error!");
		return (1);
	}
	sa.sa_handler = ft_confirm;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	ft_send_message(pid, argv[2]);
	ft_send_packet(pid, "\n");
	return (0);
}
