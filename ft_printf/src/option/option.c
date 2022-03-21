/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 15:16:14 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:08:56 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** octet[5]
**  + - #   0 precision  champs
**  0 0 0 0 0   0          0
*/

#include "ft_printf.h"

int	ft_option_int(long long nb, int octet[7])
{
	int retn;
	int pres;

	retn = 0;
	!(nb == 0 && octet[5] == 0) ? retn = nbr_len_base(nb, 10) : 0;
	pres = retn;
	octet[5] != -1 ? octet[4] = 0 : 0;
	retn < octet[5] ? retn = octet[5] : 0;
	(octet[0] && nb >= 0) || nb < 0 ? retn += 1 : 0;
	octet[3] && nb >= 0 && !octet[0] ? retn += 1 : 0;
	octet[4] && octet[0] && nb >= 0 ? ft_putchar('+') : 0;
	octet[4] && octet[3] && !octet[0] && nb >= 0 ? ft_putchar(' ') : 0;
	octet[4] && nb < 0 ? ft_putchar('-') : 0;
	octet[4] && nb < 0 ? nb = -nb : 0;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	!octet[4] && octet[0] && nb >= 0 ? ft_putchar('+') : 0;
	!octet[4] && octet[3] && !octet[0] && nb >= 0 ? ft_putchar(' ') : 0;
	octet[5] != -1 && nb < 0 ? ft_putchar('-') : 0;
	octet[5] != -1 && nb < 0 ? nb = -nb : 0;
	while (pres < octet[5])
		pres += ft_putchar('0');
	!(nb == 0 && octet[5] == 0) ? ft_putnbr(nb) : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}

int	ft_option_unsigned_int(unsigned long long nb, int octet[7])
{
	int retn;
	int pres;

	retn = 0;
	!(nb == 0 && !octet[5]) ? retn = unbr_len_base(nb, 10) : 0;
	pres = retn;
	octet[5] != -1 ? octet[4] = 0 : 0;
	retn < octet[5] ? retn = octet[5] : 0;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	while (pres < octet[5])
		pres += ft_putchar('0');
	!(nb == 0 && !octet[5]) ? ft_putunbr(nb) : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}

int	ft_option_octale(unsigned long long nb, int octet[7])
{
	int retn;
	int pres;

	retn = 0;
	!(nb == 0 && !octet[5]) ? retn = unbr_len_base(nb, 8) : 0;
	(octet[2] && nb != 0) || (octet[2] && !octet[5]) ? retn += 1 : 0;
	pres = retn;
	octet[5] != -1 ? octet[4] = 0 : 0;
	retn < octet[5] ? retn = octet[5] : 0;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	(octet[2] && nb != 0) || (octet[2] && !octet[5]) ? ft_putchar('0') : 0;
	while (pres < octet[5])
		pres += ft_putchar('0');
	!(nb == 0 && !octet[5]) ? ft_putnbr_in_octo(nb) : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}

int	ft_option_x(unsigned long long nb, int octet[7])
{
	int retn;
	int pres;

	retn = 0;
	!(nb == 0 && !octet[5]) ? retn = unbr_len_base(nb, 16) : 0;
	octet[2] && nb != 0 ? retn += 2 : 0;
	pres = retn;
	octet[5] != -1 ? octet[4] = 0 : 0;
	retn < octet[5] ? retn = octet[5] : 0;
	octet[2] && octet[4] && nb != 0 ? ft_putstr("0x") : 0;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	octet[2] && !octet[4] && nb != 0 ? ft_putstr("0x") : 0;
	while (pres < octet[5])
		pres += ft_putchar('0');
	!(nb == 0 && !octet[5]) ? ft_putnbr_in_hexa_x(nb) : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}

int	ft_option_xx(unsigned long long nb, int octet[7])
{
	int retn;
	int pres;

	retn = 0;
	!(nb == 0 && !octet[5]) ? retn = unbr_len_base(nb, 16) : 0;
	octet[2] && nb != 0 ? retn += 2 : 0;
	pres = retn;
	octet[5] != -1 ? octet[4] = 0 : 0;
	retn < octet[5] ? retn = octet[5] : 0;
	octet[2] && octet[4] && nb != 0 ? ft_putstr("0X") : 0;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	octet[2] && !octet[4] && nb != 0 ? ft_putstr("0X") : 0;
	while (pres < octet[5])
		pres += ft_putchar('0');
	!(nb == 0 && !octet[5]) ? ft_putnbr_in_hexa_xx(nb) : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}
