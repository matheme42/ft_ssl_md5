/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstrc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:52:22 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 15:45:50 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrc(const char *str, const char c)
{
	if (!str)
		return (0);
	write(1, str, ft_strlenc(str, c));
	return (ft_strlenc(str, c));
}
