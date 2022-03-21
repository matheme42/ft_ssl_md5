/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   long_long.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 15:01:58 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 12:53:25 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** voici le fichier correspondant a l'option %ll(diouxX)
*/

/*
** %u
*/

int	ft_putulonglong(unsigned long long n, int octet[7])
{
	return (ft_option_unsigned_int(n, octet));
}

/*
** %d %i
*/

int	ft_putlonglong(long long n, int octet[7])
{
	return (ft_option_int(n, octet));
}

/*
** %o
*/

int	ft_putlonglong_in_octo(unsigned long long n, int octet[7])
{
	return (ft_option_octale(n, octet));
}

/*
** %x
*/

int	ft_putlonglong_in_hexa_x(unsigned long long adr, int octet[7])
{
	return (ft_option_x(adr, octet));
}

/*
** %X
*/

int	ft_putlonglong_in_hexa_xx(unsigned long long adr, int octet[7])
{
	return (ft_option_xx(adr, octet));
}
