/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putadress.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 09:51:40 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:07:51 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(const void *adresse, int octet[7])
{
	int retn;
	int pres;

	retn = ft_strlen("0x");
	octet[5] ? retn += unbr_len_base((ULL)adresse, 16) : 0;
	pres = retn - 2;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	ft_putstr("0x");
	while (pres++ < octet[5])
		retn += ft_putchar('0');
	octet[5] ? ft_putnbr_in_hexa_x((ULL)adresse) : 0;
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}
