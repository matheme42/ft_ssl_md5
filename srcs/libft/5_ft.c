/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:09:27 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:10:55 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int s1_len, int s2_len)
{
	char	*str;
	int		l_s1;
	int		l_s2;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strndup((char*)s1, s1_len));
	if (!s1 && s2)
		return (ft_strndup((char*)s2, s2_len));
	str = NULL;
	if ((str = (char *)ft_malloc(sizeof(char) * ((s1_len + s2_len) + 1))) == NULL)
		return (NULL);
	l_s1 = -1;
	while (++l_s1 < s1_len)
		str[l_s1] = s1[l_s1];
	l_s2 = -1;
	while (++l_s2 < s2_len)
		str[l_s1 + l_s2] = s2[l_s2];
	str[l_s1 + l_s2] = '\0';
	return (str);
}

char		*ft_strndup(char *s1, int n)
{
	int		i;
	char	*s2;

	if (!(s2 = ft_strnew(n)))
		return (NULL);
	i = -1;
	while (++i < n)
		s2[i] = s1[i];
	return (s2);
}

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
