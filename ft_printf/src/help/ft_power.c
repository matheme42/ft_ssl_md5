/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_power.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/06 11:01:41 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 13:57:43 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_power(long long nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (ft_power(nb, power - 1) * nb);
}
