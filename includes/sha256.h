/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:56:43 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 09:50:37 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include "ft_ssl.h"

#define LIST_OPTION "pqrhs"
#define P (option & 1)
#define Q (option & 2)
#define R (option & 4)
#define S (option & 8)
#define H (option & 16)

/****************************** MACROS ******************************/
#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

typedef struct g_sha256 {
	unsigned char       data[64];
	unsigned int        datalen;
	unsigned long long  bitlen;
	unsigned int        state[8];
}               t_sha256;


typedef struct g_option {
    char *s;
} t_option;

char        **sha256_get_option(char **argv, int *option, t_option *complexe);
char        *sha256_algo(int option, int file_len, char *file);
void        sha256_output(char *file_name, char *hash, int option);
int         sha256_usage();

#endif