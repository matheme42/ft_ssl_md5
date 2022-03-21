/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:58:15 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:00:12 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	swap_uint8t(uint8_t nb)
{
	return ((nb << 4 & 0xff00) | (nb >> 4 & 0x00ff));
}

uint16_t	swap_uint16t(uint16_t nb)
{
    return (nb << 8) | (nb >> 8 );
}

uint32_t	swap_uint32t(uint32_t nb)
{
	return ((nb >> 24 & 0xff) | (nb >> 8 & 0xff00) | (nb << 8 & 0xff0000) | (nb << 24 & 0xff000000));
}

uint64_t	swap_uint64t(uint64_t nb)
{
	nb = (nb & 0x00000000FFFFFFFF) << 32 | (nb & 0xFFFFFFFF00000000) >> 32;
	nb = (nb & 0x0000FFFF0000FFFF) << 16 | (nb & 0xFFFF0000FFFF0000) >> 16;
	nb = (nb & 0x00FF00FF00FF00FF) << 8 | (nb & 0xFF00FF00FF00FF00) >> 8;
	return (nb);
}

uint64_t swap_byte(uint64_t k, size_t size)
{	
	if (size == sizeof(uint8_t))
		k = swap_uint8t((uint8_t) k);
	else if (size == sizeof(uint16_t))
		k = swap_uint16t((uint16_t) k);
	else if (size == sizeof(uint32_t))
		k = swap_uint32t((uint32_t) k);
	else if (size == sizeof(uint64_t))
		k = swap_uint64t((uint64_t) k);
	return (k);
}