/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:11:37 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:12:32 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = start;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = ft_malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (s[i] && k++ < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

static	size_t	ft_lenfromto(const char *s, size_t i, char c)
{
	size_t j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

static	size_t	nbmots(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			n++;
		}
	}
	return (n);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (!(tab = ft_malloc(sizeof(tab) * (nbmots(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			tab[j] = ft_strsub(s, i, ft_lenfromto(s, i, c));
			i = i + ft_lenfromto(s, i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}