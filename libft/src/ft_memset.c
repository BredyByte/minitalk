/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:39:35 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/27 18:07:25 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*byte_ptr;
	unsigned char	byte_value;
	size_t			i;

	byte_ptr = (unsigned char *)ptr;
	byte_value = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		byte_ptr[i] = byte_value;
		i++;
	}
	return (ptr);
}
