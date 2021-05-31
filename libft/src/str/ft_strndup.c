/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:30:24 by rlegendr          #+#    #+#             */
/*   Updated: 2021/05/17 17:23:45 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_str.h"

char		*ft_strndup(char *s1, int n)
{
	int		i;
	char	*tab;

	if (!(tab = (char *)ft_malloc(sizeof(char) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tab[i] = s1[i];
		i++;
	}
	return (tab);
}
