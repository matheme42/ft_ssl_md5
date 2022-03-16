/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:04:14 by matheme           #+#    #+#             */
/*   Updated: 2022/03/15 22:01:16 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include "libft.h"

// defini la liste de tous les algos disponibles
#define LIST_ALGO "md5 sha256 whirlpool"

#define MAX_ALGO_NAME_SIZE 10

/// Fonction d'erreur
void	*usage_algo(char *algo);
int     usage();
void    usage_open(char *file);
void    usage_read(char *file);
void    usage_option(const char option);
void    usage_complexe_option(const char option, char *explain, char *exemple);

// get_file
char	*get_file_from_standard_entry(size_t *size, int force);
char	*get_file_from_fd(const int fd, size_t *size);
int     try_get_fd_from_string(char *s);

/// fonction algorithme
void    md5(char **av);
void    sha256(char **av);
void    whirlpool(char **av);

#endif