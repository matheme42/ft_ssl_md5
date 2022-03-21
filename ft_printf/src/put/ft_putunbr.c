/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putunbr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 17:44:44 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 15:21:44 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned long long n)
{
	unsigned long long	t;
	unsigned long long	r;
	int					retn;

	t = 1;
	retn = 0;
	r = (unsigned long long)n;
	while (r >= 10)
	{
		r = r / 10;
		t *= 10;
	}
	r = (unsigned long long)n;
	while (t >= (unsigned long long)1)
	{
		ft_putchar(r / t + '0');
		r = r % t;
		retn++;
		t /= 10;
	}
	return (retn);
}
