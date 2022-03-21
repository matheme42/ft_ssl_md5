/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option_diouxx.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 14:03:21 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 15:04:23 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** fichier contenant les option %h %hh %l %ll
*/

int	gestion_hh(const char *f, va_list ptr, int i, int octet[7])
{
	int retn;

	retn = 0;
	f[i] == 'd' ? retn = ft_putnchar(va_arg(ptr, long long), octet) : 0;
	f[i] == 'o' ? retn = ft_putnchar_in_octo(va_arg(ptr, long long), octet) : 0;
	f[i] == 'u' ? retn = ft_putnuchar(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'i' ? retn = ft_putnchar(va_arg(ptr, long long), octet) : 0;
	f[i] == 'x' ? retn = ft_putnchar_in_hexa_x(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'X' ? retn = ft_putnchar_in_hexa_xx(va_arg(ptr, ULL), octet) : 0;
	return (retn);
}

int	gestion_h(const char *f, va_list ptr, int i, int octet[7])
{
	int retn;

	retn = 0;
	f[i] == 'h' ? retn = gestion_hh(f, ptr, i + 1, octet) : 0;
	f[i] == 'd' ? retn = ft_putshort(va_arg(ptr, long long), octet) : 0;
	f[i] == 'o' ? retn = ft_putshort_in_octo(va_arg(ptr, long long), octet) : 0;
	f[i] == 'u' ? retn = ft_putushort(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'i' ? retn = ft_putshort(va_arg(ptr, long long), octet) : 0;
	f[i] == 'x' ? retn = ft_putshort_in_hexa_x(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'X' ? retn = ft_putshort_in_hexa_xx(va_arg(ptr, ULL), octet) : 0;
	return (retn);
}

int	gestion_ll(const char *f, va_list ptr, int i, int octet[7])
{
	int retn;

	retn = 0;
	f[i] == 'd' ? retn = ft_putlonglong(va_arg(ptr, long long), octet) : 0;
	f[i] == 'o' ? retn = ft_putlonglong_in_octo(va_arg(ptr, LL), octet) : 0;
	f[i] == 'u' ? retn = ft_putulonglong(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'i' ? retn = ft_putlonglong(va_arg(ptr, long long), octet) : 0;
	f[i] == 'x' ? retn = ft_putlonglong_in_hexa_x(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'X' ? retn = ft_putlonglong_in_hexa_xx(va_arg(ptr, ULL), octet) : 0;
	return (retn);
}

int	gestion_l(const char *f, va_list ptr, int i, int octet[7])
{
	int retn;

	retn = 0;
	f[i] == 'l' ? retn = gestion_ll(f, ptr, i + 1, octet) : 0;
	f[i] == 'd' ? retn = ft_putlong(va_arg(ptr, long long), octet) : 0;
	f[i] == 'o' ? retn = ft_putlong_in_octo(va_arg(ptr, long long), octet) : 0;
	f[i] == 'u' ? retn = ft_putulong(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'i' ? retn = ft_putlong(va_arg(ptr, long long), octet) : 0;
	f[i] == 'x' ? retn = ft_putlong_in_hexa_x(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'X' ? retn = ft_putlong_in_hexa_xx(va_arg(ptr, ULL), octet) : 0;
	f[i] == 'f' ? retn = ges_d((LD)va_arg(ptr, double), octet) : 0;
	return (retn);
}
