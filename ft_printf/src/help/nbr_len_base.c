/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nbr_len_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:28:57 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 16:20:23 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		nbr_len_base(long long n, int base)
{
	size_t	t;

	t = 1;
	if (n > 0)
		n = -n;
	while (n / ft_power(base, t) <= -1)
		t++;
	return (t);
}
