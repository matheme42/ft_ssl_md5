/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_in_octo.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 17:40:38 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 16:55:59 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_in_octo(unsigned long long nb)
{
	static char *base = "01234567";

	if (nb / 8 > 0)
		return (ft_putnbr_in_octo(nb / 8) + ft_putchar(base[nb % 8]));
	return (ft_putchar(base[nb % 8]));
}
