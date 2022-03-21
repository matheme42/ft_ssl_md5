/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_in_hexa.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 17:28:26 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:56:05 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_in_hexa_x(unsigned long long adr)
{
	static char *base = "0123456789abcdef\0";

	if (adr / 16 > 0)
		return (ft_putnbr_in_hexa_x(adr / 16) + ft_putchar(base[adr % 16]));
	return (ft_putchar(base[adr % 16]));
}

int	ft_putnbr_in_hexa_xx(unsigned long long adr)
{
	static char *base = "0123456789ABCDEF\0";

	if (adr / 16 > 0)
		return (ft_putnbr_in_hexa_xx(adr / 16) + ft_putchar(base[adr % 16]));
	return (ft_putchar(base[adr % 16]));
}
