/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:23:55 by matheme           #+#    #+#             */
/*   Updated: 2022/03/15 22:02:17 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void usage_option(const char option)
{
	ft_printf("unknown option '-%c' ", option);
	ft_printf("try -h for help\n");
	exit(1);
}

void usage_complexe_option(const char option, char *explain, char *exemple)
{
	ft_printf("error option '-%c' %s\n",option, explain);
	if (exemple)
		ft_printf("exemple:\n%s \n", exemple);
	exit(1);
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

int usage()
{
	ft_printf("usage: ft_ssl [command opts] [command args]\n");
	list_command();
	return (1);
}

void usage_open(char *file)
{
	ft_printf("unable to open the file name '%s'\n", file);
}

void usage_read(char *file)
{
	ft_printf("unable to read the file name '%s'\n", file);
}