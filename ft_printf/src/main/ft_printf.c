/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:03:11 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 12:15:20 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void	init_octet(int (*octet)[7])
{
	(*octet)[0] = 0;
	(*octet)[1] = 0;
	(*octet)[2] = 0;
	(*octet)[3] = 0;
	(*octet)[4] = 0;
	(*octet)[5] = -1;
	(*octet)[6] = 0;
}

/*
** octet[5]
**  + - #   0 precision  champs
**  0 0 0 0 0   0          0
*/

static int	detect_option(const char *f, int i, int (*octet)[7])
{
	f[i] == '+' && (*octet)[0] == 0 ? (*octet)[0] = 1 : 0;
	f[i] == '-' && (*octet)[1] == 0 ? (*octet)[1] = 1 : 0;
	f[i] == '#' && (*octet)[2] == 0 ? (*octet)[2] = 1 : 0;
	f[i] == ' ' && (*octet)[3] == 0 ? (*octet)[3] = 1 : 0;
	f[i] == '0' && (*octet)[4] == 0 ? (*octet)[4] = 1 : 0;
	if (f[i] == '.')
	{
		(*octet)[5] = ft_atoi(&f[i + 1]);
		while (f[i + 1] >= '0' && f[i + 1] <= '9')
			i++;
	}
	else if (f[i] >= '0' && f[i] <= '9')
	{
		(*octet)[6] = ft_atoi(&f[i]);
		while (f[i + 1] >= '0' && f[i + 1] <= '9')
			i++;
	}
	if (f[i] == '+' || f[i] == '-' || f[i] == '#' || f[i] == ' ' ||
							f[i] == '.' || (f[i] >= '0' && f[i] <= '9'))
		return (detect_option(f, i + 1, octet));
	return (i);
}

static int	put_pourcent(const char *f, va_list ptr, int oct[7], int i)
{
	int retn;

	retn = 0;
	if (f[i] == 'h' || f[i] == 'l' || f[i] == 'L')
	{
		f[i] == 'h' ? retn = gestion_h(f, ptr, i + 1, oct) : 0;
		f[i] == 'l' ? retn = gestion_l(f, ptr, i + 1, oct) : 0;
		f[i] == 'L' && f[i + 1] == 'f' ? retn = ges_d(va_arg(ptr, LD), oct) : 0;
		return (retn);
	}
	f[i] == 'd' ? retn = ft_putint(va_arg(ptr, long long), oct) : 0;
	f[i] == 'o' ? retn = ft_putint_in_octo(va_arg(ptr, ULL), oct) : 0;
	f[i] == 'u' ? retn = ft_putuint(va_arg(ptr, ULL), oct) : 0;
	f[i] == 'i' ? retn = ft_putint(va_arg(ptr, long long), oct) : 0;
	f[i] == 'x' ? retn = ft_putint_in_hexa_x(va_arg(ptr, ULL), oct) : 0;
	f[i] == 'X' ? retn = ft_putint_in_hexa_xx(va_arg(ptr, ULL), oct) : 0;
	f[i] == 'f' ? retn = ges_d(va_arg(ptr, double), oct) : 0;
	f[i] == 'p' ? retn = ft_putadress(va_arg(ptr, void *), oct) : 0;
	f[i] == 'c' ? retn = option_char(va_arg(ptr, long long), oct) : 0;
	f[i] == 's' ? retn = ft_option_str(va_arg(ptr, char *), oct) : 0;
	f[i] == '%' ? retn = option_char('%', oct) : 0;
	return (retn);
}

int			find_carac(char c)
{
	static char	t[11] = {'d', 'o', 'u', 'i', 'x', 'X', 'f', 'p', 'c', 's', '%'};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (c == t[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_printf(const char *forma, ...)
{
	va_list	argptr;
	int		retn;
	int		octet[7];
	int		i;

	va_start(argptr, forma);
	retn = 0;
	while (*forma)
	{
		retn += ft_putstrc(forma, '%');
		i = ft_strlenc(forma, '%');
		if (forma[i] == '%')
		{
			init_octet(&octet);
			i = detect_option(forma, i + 1, &octet);
			retn += put_pourcent(forma, argptr, octet, i);
			forma[i] == 'h' || forma[i] == 'l' || forma[i] == 'L' ? i += 1 : 0;
			forma[i] == 'h' || forma[i] == 'l' ? i += 1 : 0;
			find_carac(forma[i]) ? i += 1 : 0;
		}
		forma = &forma[i];
	}
	va_end(argptr);
	return (retn);
}
