/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 14:06:53 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:57:05 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** voici le fichier correspondant au diouxX classique
*/

/*
** %u
*/

int	ft_putuint(unsigned long long n, int octet[7])
{
	unsigned int nb;

	nb = ((unsigned int)n);
	return (ft_option_unsigned_int((long long)nb, octet));
}

/*
** %d %i
*/

int	ft_putint(long long n, int octet[7])
{
	int nb;

	nb = (int)n;
	return (ft_option_int((long long)nb, octet));
}

/*
** %o
*/

int	ft_putint_in_octo(unsigned long long n, int octet[7])
{
	unsigned int nb;

	nb = ((unsigned int)n);
	return (ft_option_octale((unsigned long long)nb, octet));
}

/*
** %x
*/

int	ft_putint_in_hexa_x(unsigned long long adr, int octet[7])
{
	unsigned int nb;

	nb = (unsigned int)adr;
	return (ft_option_x((unsigned long long)nb, octet));
}

/*
** %X
*/

int	ft_putint_in_hexa_xx(unsigned long long adr, int octet[7])
{
	unsigned int nb;

	nb = (unsigned int)adr;
	return (ft_option_xx((unsigned long long)nb, octet));
}
