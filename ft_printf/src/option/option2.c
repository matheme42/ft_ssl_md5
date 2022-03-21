/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 15:39:03 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:07:30 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_option_str(const char *s, int oct[7])
{
	int retn;
	int pres;

	!s ? retn = 6 : 0;
	oct[5] == -1 && s ? retn = ft_strlen(s) : 0;
	oct[5] != -1 && oct[5] < (int)ft_strlen(s) ? retn = oct[5] : 0;
	oct[5] != -1 && oct[5] >= (int)ft_strlen(s) ? retn = (int)ft_strlen(s) : 0;
	pres = retn;
	!oct[1] ? retn = gestion_champs(retn, oct) : 0;
	oct[5] == -1 ? ft_putstr(s) : 0;
	oct[5] != -1 ? ft_putnstr(s, oct[5]) : 0;
	oct[1] ? retn = gestion_champs(retn, oct) : 0;
	return (retn);
}

int		option_char(char c, int octet[7])
{
	int retn;

	retn = 1;
	!octet[1] ? retn = gestion_champs(retn, octet) : 0;
	ft_putchar(c);
	octet[1] ? retn = gestion_champs(retn, octet) : 0;
	return (retn);
}
