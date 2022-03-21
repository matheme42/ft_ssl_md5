/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   long.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 14:35:50 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:56:47 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** voici le fichier correspondant a l'option %l(diouxX)
*/

/*
** %lu
*/

int	ft_putulong(unsigned long long n, int octet[7])
{
	unsigned long nb;

	nb = ((unsigned long)n);
	return (ft_option_unsigned_int((unsigned long long)nb, octet));
}

/*
** %ld %li
*/

int	ft_putlong(long long n, int octet[7])
{
	long nb;

	nb = ((long)n);
	return (ft_option_int((long long)nb, octet));
}

/*
** %lo
*/

int	ft_putlong_in_octo(unsigned long long n, int octet[7])
{
	unsigned long nb;

	nb = ((unsigned long)n);
	return (ft_option_octale((unsigned long long)nb, octet));
}

/*
** %lx
*/

int	ft_putlong_in_hexa_x(unsigned long long adr, int octet[7])
{
	unsigned long nb;

	nb = (unsigned long)adr;
	return (ft_option_x((unsigned long long)nb, octet));
}

/*
** %lX
*/

int	ft_putlong_in_hexa_xx(unsigned long long adr, int octet[7])
{
	unsigned long nb;

	nb = (unsigned long)adr;
	return (ft_option_xx((unsigned long long)nb, octet));
}
