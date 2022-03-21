/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:23:55 by matheme           #+#    #+#             */
/*   Updated: 2022/03/18 16:17:05 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void *usage_complexe_option(const char option, char *explain, char *exemple)
{
	ft_printf("error option '-%c' %s\n",option, explain);
	if (exemple)
		ft_printf("exemple:\n%s \n", exemple);
	return (NULL);
}

static void list_command()
{
	char	**algos;
	int		i;

	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	i = -1;
	algos = ft_strsplit(LIST_ALGO, ' ');
	while (algos[++i])
		ft_printf("%s\n", algos[i]);
	ft_printf("\nCipher commands:\n\n");
}

void *usage_algo(char *algo)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command\n\n", algo);
	list_command();
	return (NULL);
}
