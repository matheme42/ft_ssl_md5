/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:51:32 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:34:08 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	unsigned char	u;

	u = c;
	write(1, &(u), 1);
	return (0);
}

char	*ft_strnew(int size)
{
	char	*str;

	if (!(str = ft_malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srcs;
	size_t	i;

	dest = (char *)dst;
	srcs = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	dst = (void*)dest;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a] && s[a] != (char)c)
		a++;
	if (s[a] == '\0' && c != '\0')
		return (NULL);
	return ((char*)&s[a]);
}

void			*ft_malloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)))
        ft_memset(ret, '\0', size);
	else
    	ft_putstr("memory allocation failed\n");
	return (ret);
}