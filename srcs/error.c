/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:23:55 by matheme           #+#    #+#             */
/*   Updated: 2021/01/07 14:37:47 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void usage_option(const char option)
{
	ft_printf("unknown option '-%c'\n", option);
	ft_printf("options are\n");
}

void usage_algo(char *algo)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command\n\n", algo);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n\n");
}

void usage()
{
	ft_printf("usage: ft_ssl [command opts] [command args]\n");
}