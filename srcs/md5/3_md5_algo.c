/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_md5_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:04:46 by matheme           #+#    #+#             */
/*   Updated: 2022/03/15 21:16:50 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

static char r(int id) {
    static const char r[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };
    return (r[id]);
}

static int k(int id) {
    static const uint32_t k[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };
    return (k[id]);
}

static t_h md5_second_loop(t_h src_h, uint32_t *w)
{
    uint32_t    i;
    uint32_t    f;
    uint32_t    g;
    t_h         h;
    uint32_t    temp;

    i = 0;
    ft_memcpy(&h, &src_h, sizeof(h));
    while(i < 64) {

        if (i < 16) {
            f = (h.h1 & h.h2) | ((~h.h1) & h.h3);
            g = i;
        } else if (i < 32) {
            f = (h.h3 & h.h1) | ((~h.h3) & h.h2);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            f = h.h1 ^ h.h2 ^ h.h3;
            g = (3 * i + 5) % 16;
        } else {
            f = h.h2 ^ (h.h1 | (~h.h3));
            g = (7 * i) % 16;
        }

        temp = h.h3;
        h.h3 = h.h2;
        h.h2 = h.h1;
        h.h1 = h.h1 + LEFTROTATE((h.h0 + f + k(i) + w[g]), r(i));
        h.h0 = temp;
        i++;
    }
    src_h.h0 += h.h0;
    src_h.h1 += h.h1;
    src_h.h2 += h.h2;
    src_h.h3 += h.h3;
    return (src_h);
}


char *md5_algo(int option, int file_len, char *file)
{
    int     new_len;
    int     offset;
    uint8_t *msg;
    t_h     h;
    char    *hash;


    h.h0 = 0x67452301;
    h.h1 = 0xEFCDAB89;
    h.h2 = 0x98BADCFE;
    h.h3 = 0x10325476;
    new_len = ((((file_len + 8) / 64) + 1) * 64) - 8;
    if (!(msg = ft_malloc(new_len + 64)))
        return (NULL);
    ft_memcpy(msg, file, file_len);
    msg[file_len] = 128;
    *(int*)(msg + new_len) = 8 * file_len;
    offset = 0;
    while (offset < new_len)
    {
        h = md5_second_loop(h, (uint32_t *)(msg + offset));
        offset += (512 / 8);
    }
    h.h0 = swap_byte(h.h0, sizeof(h.h0));
    h.h1 = swap_byte(h.h1, sizeof(h.h1));
    h.h2 = swap_byte(h.h2, sizeof(h.h2));
    h.h3 = swap_byte(h.h3, sizeof(h.h3));
    free(msg);
    file[file_len] = '\0';
    
    hash = ft_utoa_base_champ(h.h0, 16, 8);
    ft_strjoin_free(&hash, ft_utoa_base_champ(h.h1, 16, 8));
    ft_strjoin_free(&hash, ft_utoa_base_champ(h.h2, 16, 8));
    ft_strjoin_free(&hash, ft_utoa_base_champ(h.h3, 16, 8));
    return (hash);
}

