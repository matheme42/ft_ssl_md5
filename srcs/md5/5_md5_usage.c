/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_md5_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:27:02 by matheme           #+#    #+#             */
/*   Updated: 2022/03/11 15:55:33 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void        md5_usage()
{
    ft_printf("./ft_ssl md5 [-pqr] [-s 'string']\n");
    ft_printf(" -p  echo STDIN to STDOUT and append the checksum to STDOUT\n");
    ft_printf(" -q  quiet mode\n");
    ft_printf(" -r  reverse the format of the output\n");
    ft_printf(" -s  print the sum of the given string\n");
    exit(0);
}