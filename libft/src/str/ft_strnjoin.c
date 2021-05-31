/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:53:41 by matheme           #+#    #+#             */
/*   Updated: 2021/05/17 17:23:17 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_str.h"

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