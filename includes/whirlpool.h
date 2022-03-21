/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:56:43 by matheme           #+#    #+#             */
/*   Updated: 2022/03/11 17:43:28 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whirlpool_H
# define whirlpool_H

# include "ft_ssl.h"

#define LIST_OPTION "pqrhs"
#define P (option & 1)
#define Q (option & 2)
#define R (option & 4)
#define S (option & 8)
#define H (option & 16)

typedef struct g_option {
    char *s;
} t_option;

char        **whirlpool_get_option(char **argv, int *option, t_option *complexe);
char        *whirlpool_algo(int option, int file_len, char *file);
void        whirlpool_output(char *file_name, char *hash, int option);
int         whirlpool_usage();

#endif