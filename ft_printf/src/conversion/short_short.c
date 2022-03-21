/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   short_short.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 14:15:57 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:56:36 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** voici le fichier correspondant a l'option %hh(diouxX)
*/

/*
** %hhu
*/

int	ft_putnuchar(unsigned long long n, int octet[7])
{
	unsigned char nb;

	nb = ((unsigned char)n);
	return (ft_option_unsigned_int((long long)nb, octet));
}

/*
** %hhd %hhi
*/

int	ft_putnchar(long long n, int octet[7])
{
	char nb;

	nb = ((char)n);
	return (ft_option_int((long long)nb, octet));
}

/*
** %hho
*/

int	ft_putnchar_in_octo(long long n, int octet[7])
{
	unsigned char nb;

	nb = ((unsigned char)n);
	return (ft_option_octale((unsigned long long)nb, octet));
}

/*
** %hhx
*/

int	ft_putnchar_in_hexa_x(unsigned long long adr, int octet[7])
{
	unsigned char nb;

	nb = (unsigned char)adr;
	return (ft_option_x((unsigned long long)nb, octet));
}

/*
** %hhX
*/

int	ft_putnchar_in_hexa_xx(unsigned long long adr, int octet[7])
{
	unsigned char nb;

	nb = (unsigned char)adr;
	return (ft_option_xx((unsigned long long)nb, octet));
}
