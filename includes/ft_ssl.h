/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:04:14 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:22:04 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include "libft.h"
#include "ft_printf.h"

// defini la liste de tous les algos disponibles
#define LIST_ALGO "md5 sha256 whirlpool"

#define MAX_ALGO_NAME_SIZE 10

/// Fonction d'erreur
void	*usage_algo(char *algo);
void    *usage_complexe_option(const char option, char *explain, char *exemple);

// get_file
int     try_get_fd_from_string(char *s);
char	*get_file_from_fd(const int fd, size_t *size);
char	*get_file_from_standard_entry(size_t *size, int force);

/// algorithme
int    md5(char **av);
int    sha256(char **av);
int    whirlpool(char **av);

#endif