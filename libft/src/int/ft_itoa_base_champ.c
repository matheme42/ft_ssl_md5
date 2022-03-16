/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:55:28 by matheme           #+#    #+#             */
/*   Updated: 2022/03/15 20:57:10 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"

char	*ft_utoa_base_champ(unsigned long long nb, int bx, int champ)
{
	static char base[17] = "0123456789abcdef\0";
	char		*str;

	if ((nb / bx > 0 && champ > 1) || champ > 1) {
		str = ft_utoa_base_champ(nb / bx, bx, champ - 1);
		ft_strjoin_free(&str, ft_strndup(&base[nb % bx], 1));
		return (str);
	}
	return (ft_strndup(&base[nb % bx], 1));
}
