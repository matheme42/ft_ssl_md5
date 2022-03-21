/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_put_double.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 15:00:41 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 15:25:47 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

long double	gestion_arrondie(long double n, int precision)
{
	long double m;
	long double power;

	m = n;
	power = 1;
	m < 0 ? n = -n : 0;
	n -= (long)n;
	while (precision >= 1)
	{
		n *= 10;
		n -= (int)n;
		power /= 10;
		precision--;
	}
	if (n < 0.5 && n > -0.5)
		return (m);
	else if (n >= 0.5 && m >= 0)
		return (m + power);
	else if (n >= 0.5 && m < 0)
		return (m - power);
	return (n);
}

int			ft_nbrlen_long_double(long double n)
{
	long double	t;
	int			retn;

	t = 1;
	retn = 1;
	n < 0 ? retn += 1 : 0;
	while (n / t >= 10 || n / t <= -10)
	{
		retn += 1;
		t *= 10;
	}
	return (retn);
}

int			ft_putnbr_long_double(long double n)
{
	long double	t;
	int			retn;

	t = 1;
	retn = 0;
	n < 0 ? retn += ft_putchar('-') : 0;
	while (n / t >= 10 || n / t <= -10)
		t *= 10;
	while (t >= 1)
	{
		n >= 0 ? ft_putchar((int)(n / t) + '0') : 0;
		n < 0 ? ft_putchar(-(int)(n / t) + '0') : 0;
		n = n - (int)(n / t) * t;
		t /= 10;
		retn++;
	}
	return (retn);
}

int			ft_put_double(long double n, int precision, int z)
{
	if (z == 0)
	{
		z = ft_putnbr_long_double(n);
		if (precision >= 1)
			z += ft_putchar('.');
	}
	if (precision >= 1)
	{
		n -= (long)n;
		if (n > 0)
			n = -n;
		n *= 10;
		ft_putchar(-(long)n + '0');
		n = n - (long)n;
	}
	if (precision >= 1)
		return (ft_put_double(n, precision - 1, z + 1));
	return (z);
}

int			ges_d(long double n, int octet[7])
{
	int retn;

	retn = 0;
	octet[5] == -1 ? octet[5] = 6 : 0;
	if (n == n && n < 1.0 / 0.0 && n > -1.0 / 0.0)
		retn = ft_nbrlen_long_double(n) + octet[5];
	n != n || n >= 1.0 / 0.0 || n <= -1.0 / 0.0 ? retn = 3 : 0;
	n >= 0 && octet[0] && n == n ? retn += 1 : 0;
	n >= 0 && !octet[0] && octet[3] && n == n ? retn += 1 : 0;
	octet[5] > 0 && n == n && n < 1.0 / 0.0 ? retn += 1 : 0;
	n = gestion_arrondie(n, octet[5]);
	!octet[1] && !octet[4] ? retn = gestion_champs(retn, octet) : 0;
	n >= 0 && octet[0] ? ft_putchar('+') : 0;
	n >= 0 && !octet[0] && octet[3] ? ft_putchar(' ') : 0;
	!octet[1] && octet[4] && n < 0 ? ft_putchar('-') : 0;
	!octet[1] && octet[4] && n < 0 ? n = -n : 0;
	!octet[1] && octet[4] ? retn = gestion_champs(retn, octet) : 0;
	n >= 1.0 / 0.0 ? ft_putstr("inf") : 0;
	n <= -1.0 / 0.0 ? ft_putstr("-inf") : 0;
	if (n == n && n < 1.0 / 0.0 && n > -1.0 / 0.0)
		ft_put_double(n, octet[5], 0);
	n != n ? ft_putstr("nan") : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}
