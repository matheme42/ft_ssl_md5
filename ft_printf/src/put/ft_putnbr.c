/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:43:10 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 18:24:25 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** le putnbr sert à afficher les nombres signer c'est à dire
** %d
** %i
*/

int		ft_putnbr(long long n)
{
	long long	t;
	long long	r;
	int			retn;

	t = 1;
	retn = 0;
	if (n < 0)
		retn += ft_putchar('-');
	else
		n = -n;
	r = n;
	while (r <= -10)
	{
		r = r / 10;
		t *= 10;
	}
	while (t >= 1)
	{
		ft_putchar(-(n / t - '0'));
		n = n % t;
		retn++;
		t /= 10;
	}
	return (retn);
}
