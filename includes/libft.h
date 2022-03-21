/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:04:14 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:33:43 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// 1_ft.c
char	    *ft_strdup(char *str);
void	    ft_putstr(const char *str);
int         ft_strlen(const char *str);
char	    *ft_strstr(const char *str, const char *tofind);
void	    ft_bzero(void *elem, int i);

// 2_ft.c
int         ft_putchar(int c);
char	    *ft_strnew(int size);
void	    *ft_memcpy(void *dst, const void *src, size_t n);
char        *ft_strchr(const char *s, int c);
void		*ft_malloc(size_t size);

// 3_ft.c
uint64_t    swap_byte(uint64_t k, size_t size);


// 4_ft.c
void	    *ft_memset(void *b, int c, size_t l);
char        *ft_strjoin(char const *s1, char const *s2);
void	    ft_strdel(char **str);
char	    *ft_strcat(char *dest, char *str);
void        ft_strjoin_free(char **s1, const char *s2);

// 5_ft.c
char	    *ft_strnjoin(char const *s1, char const *s2, int s1_len, int s2_len);
char		*ft_strndup(char *s1, int n);
char	    *ft_utoa_base_champ(unsigned long long nb, int bx, int champ);

// 6_ft.c
char		**ft_strsplit(const char *s, char c);
char	    *ft_strsub(char const *s, unsigned int start, size_t len);
#endif