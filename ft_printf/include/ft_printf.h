/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:29:43 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 10:25:08 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ULL    unsigned long long
# define LL     long long
# define LD     long double

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*
** fonction d'aide exterieur
*/
size_t				ft_strlenc(const char *str, const char c);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
int					ft_putstrc(const char *str, const char c);
int					ft_atoi(const char *str);
long long			ft_power(long long nb, int power);
unsigned long long	ft_upower(ULL nb, int power);
size_t				nbr_len_base(long long n, int base);
size_t				unbr_len_base(ULL n, int base);

/*
** les putnbr_ameliorer
*/
int					ft_putnbr(long long n);
int					ft_putnbr_in_octo(ULL nb);
int					ft_putunbr(ULL n);
int					ft_putnbr_in_hexa_x(ULL adr);
int					ft_putnbr_in_hexa_xx(ULL adr);

/*
** conversion csp
*/
int					ft_putadress(const void *adresse, int octet[7]);
int					ft_putchar(char c);
int					ft_putstr(const char *str);
int					ft_putnstr(const char *str, int n);
/*
** conversion diouxX
*/
int					ft_putint(long long n, int octet[7]);
int					ft_putint_in_octo(ULL n, int octet[7]);
int					ft_putuint(ULL n, int octet[7]);
int					ft_putint_in_hexa_x(ULL adr, int octet[7]);
int					ft_putint_in_hexa_xx(ULL adr, int octet[7]);

/*
** conversion diouxX (%ll)
*/
int					gestion_ll(const char *f, va_list argptr, int i, int o[7]);

int					ft_putulonglong(ULL n, int octet[7]);
int					ft_putlonglong(long long n, int octet[7]);
int					ft_putlonglong_in_octo(ULL n, int octet[7]);
int					ft_putlonglong_in_hexa_x(ULL adr, int octet[7]);
int					ft_putlonglong_in_hexa_xx(ULL adr, int octet[7]);

/*
** conversion diouxX (%l)
*/
int					gestion_l(const char *f, va_list argptr, int i, int o[7]);

int					ft_putlong(long long n, int octet[7]);
int					ft_putlong_in_octo(ULL n, int octet[7]);
int					ft_putulong(ULL n, int octet[7]);
int					ft_putlong_in_hexa_x(ULL adr, int octet[7]);
int					ft_putlong_in_hexa_xx(ULL adr, int octet[7]);

/*
** conversion diouxX (%h)
*/
int					gestion_h(const char *f, va_list argptr, int i, int o[7]);

int					ft_putshort(long long n, int octet[7]);
int					ft_putshort_in_octo(long long n, int octet[7]);
int					ft_putushort(ULL n, int octet[7]);
int					ft_putshort_in_hexa_x(ULL adr, int octet[7]);
int					ft_putshort_in_hexa_xx(ULL adr, int octet[7]);

/*
** conversion diouxX (%hh)
*/
int					gestion_hh(const char *f, va_list argptr, int i, int o[7]);

int					ft_putnchar(long long n, int octet[7]);
int					ft_putnchar_in_octo(long long n, int octet[7]);
int					ft_putnuchar(ULL n, int octet[7]);
int					ft_putnchar_in_hexa_x(ULL adr, int octet[7]);
int					ft_putnchar_in_hexa_xx(ULL adr, int octet[7]);

/*
** convesion f
*/
int					ges_d(long double n, int octet[7]);

/*
** options
*/
int					gestion_champs(int champs, int octet[7]);

int					ft_option_unsigned_int(ULL nb, int octet[7]);
int					ft_option_int(long long n, int octet[7]);
int					ft_option_octale(ULL nb, int octet[7]);
int					ft_option_x(ULL nb, int octet[7]);
int					ft_option_xx(ULL nb, int octet[7]);
int					ft_option_str(const char *s, int octet[7]);
int					option_char(char c, int octet[7]);
#endif
