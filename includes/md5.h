/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:04:14 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 09:50:38 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include "ft_ssl.h"

#define LIST_OPTION "pqrhs"
#define P (option & 1)
#define Q (option & 2)
#define R (option & 4)
#define S (option & 8)
#define H (option & 16)

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef struct  g_h {
    int h0;
    int h1;
    int h2;
    int h3;
}               t_h;

typedef struct g_option {
    char *s;
} t_option;

char        **md5_get_option(char **argv, int *option, t_option *complexe);
char        *md5_algo(int option, int file_len, char *file);
void        md5_output(char *file_name, char *hash, int option);
int         md5_usage();

#endif