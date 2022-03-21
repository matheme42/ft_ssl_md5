/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unbr_len_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:56:24 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 13:11:53 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		unbr_len_base(unsigned long long n, int base)
{
	size_t	t;

	t = 1;
	while (n / (ULL)base >= 1)
	{
		n = n / base;
		t++;
	}
	return (t);
}
