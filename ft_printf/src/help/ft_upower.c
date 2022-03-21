/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_upower.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:59:10 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 14:14:17 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_upower(unsigned long long nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (ft_upower(nb, power - 1) * nb);
}
