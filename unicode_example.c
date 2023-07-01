/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:01:33 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/29 15:15:52 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	main(void)
{
	unsigned char	emoji_bytes[4];

	emoji_bytes[0] = 0xF0;
	emoji_bytes[1] = 0x9F;
	emoji_bytes[2] = 0x98;
	emoji_bytes[3] = 0x81;
	printf("%c%c%c%c\n",
		emoji_bytes[0], emoji_bytes[1], emoji_bytes[2], emoji_bytes[3]);
	return (0);
}
