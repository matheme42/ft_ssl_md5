/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 13:32:18 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:12:49 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(const char *str, int n)
{
	int len;
	int retn;

	len = 0;
	if (!str)
	{
		n > 6 ? write(1, "(null)", 6) : 0;
		n > 6 ? retn = 6 : 0;
		n <= 6 ? retn = write(1, "(null)", n) : 0;
		n <= 6 ? retn = n : 0;
	}
	else
	{
		len = ft_strlen(str);
		n > len ? write(1, str, len) : 0;
		n > len ? retn = len : 0;
		n <= len ? write(1, str, n) : 0;
		n <= len ? retn = n : 0;
	}
	return (retn);
}
