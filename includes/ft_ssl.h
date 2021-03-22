/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:04:14 by matheme           #+#    #+#             */
/*   Updated: 2021/01/07 14:35:45 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include "ft_int.h"
#include "ft_str.h"
#include "ft_printf.h"
#include "ft_printf_err.h"
#include "ft_mem.h"

#define LIST_OPTION "p"
#define LIST_ALGO "md5 "

#define MAX_ALGO_NAME_SIZE 10

char	**get_algo(int *ac, char **av, char **algo);
char	**get_option(int ac, char **av, int *option);

void	usage_option(const char option);
void	usage_algo(char *algo);
void	usage();

#endif