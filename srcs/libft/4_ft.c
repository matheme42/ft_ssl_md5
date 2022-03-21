/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:03:28 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:08:53 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t l)
{
	size_t			i;
	unsigned char	*r;

	i = 0;
	r = (unsigned char*)b;
	while (i < l)
	{
		r[i] = c;
		i++;
	}
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l_s1;
	int		l_s2;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup((char*)s1));
	if (!s1 && s2)
		return (ft_strdup((char*)s2));
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = NULL;
	if ((str = (char *)ft_malloc(sizeof(char) * ((l_s1 + l_s2) + 1))) == NULL)
		return (NULL);
	l_s1 = 0;
	while (s1[l_s1])
		str[i++] = s1[l_s1++];
	l_s2 = 0;
	while (s2[l_s2])
		str[i++] = s2[l_s2++];
	str[i] = '\0';
	return (str);
}

void	ft_strdel(char **str)
{
	if (*str)
		free(*str);
	(*str) = NULL;
}

char	*ft_strcat(char *dest, char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (str[j])
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (dest);
}

void	ft_strjoin_free(char **s1, const char *s2)
{
	char *ret;

	if (!(ret = ft_malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1))))
	{
		ft_strdel(s1);
		return ;
	}
	ret[0] = '\0';
	ret = ft_strcat(ret, *s1);
	ret = ft_strcat(ret, (char *)s2);
	ft_strdel(s1);
	*s1 = ret;
}
