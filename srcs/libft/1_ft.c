/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:29:30 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 09:52:07 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *elem, int i)
{
	int		j;
	char	*r;

	j = -1;
	if (!elem)
		return ;
	r = (char *)elem;
	while (++j < i)
		r[j] = 0;
}

char	*ft_strstr(const char *str, const char *tofind)
{
	int		j;
	char	*s;

	s = (char*)str;
	if (tofind[0] == '\0')
		return (s);
	while (*s)
	{
		j = 0;
		while (*(s + j) == tofind[j] && tofind[j])
			j++;
		if (tofind[j] == '\0')
			return (s);
		s++;
	}
	return (NULL);
}

int	ft_strlen(const char *str)
{
	const char *s;

	if (!str)
		return (0);
	s = str;
	while (*s != '\0')
		s++;
	return (s - str);
}

void	ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	if (!str)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}