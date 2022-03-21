/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_champs.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:03:02 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:06:15 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		gestion_champs(int champs, int octet[7])
{
	while (champs < octet[6])
	{
		octet[4] && !octet[1] ? champs += ft_putchar('0') : 0;
		!octet[4] || octet[1] ? champs += ft_putchar(' ') : 0;
	}
	return (champs);
}
