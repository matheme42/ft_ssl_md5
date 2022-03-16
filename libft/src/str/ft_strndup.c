/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:30:24 by rlegendr          #+#    #+#             */
/*   Updated: 2022/03/15 20:44:44 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_str.h"

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
