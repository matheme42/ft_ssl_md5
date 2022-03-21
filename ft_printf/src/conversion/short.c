/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   short.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 13:57:16 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:56:27 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** voici le fichier correspondant a l'option %h(diouxX)
*/

/*
** %hu
*/

int	ft_putushort(unsigned long long n, int octet[7])
{
	unsigned short nb;

	nb = ((unsigned short)n);
	return (ft_option_unsigned_int((long long)nb, octet));
}

/*
** %hd %hi
*/

int	ft_putshort(long long n, int octet[7])
{
	short nb;

	nb = ((short)n);
	return (ft_option_int((long long)nb, octet));
}

/*
** %ho
*/

int	ft_putshort_in_octo(long long n, int octet[7])
{
	unsigned short nb;

	nb = ((unsigned short)n);
	return (ft_option_octale((unsigned long long)nb, octet));
}

/*
** %hx
*/

int	ft_putshort_in_hexa_x(unsigned long long adr, int octet[7])
{
	unsigned short nb;

	nb = (unsigned short)adr;
	return (ft_option_x((unsigned long long)nb, octet));
}

/*
** %hX
*/

int	ft_putshort_in_hexa_xx(unsigned long long adr, int octet[7])
{
	unsigned short nb;

	nb = (unsigned short)adr;
	return (ft_option_xx((unsigned long long)nb, octet));
}
