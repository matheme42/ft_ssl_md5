/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:03:48 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 12:14:47 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	(*select_algo(char *algo))(char **)
{

	char	*algoname[] = {"md5", "sha256", "whirlpool", NULL};
	int		(*algofunction[])(char **) = {&md5, &sha256, &whirlpool, NULL};
	int		i;

	if (algo == NULL)
		return (NULL);
	i = -1;
	while (algoname[++i])
		if (ft_strstr(algo, algoname[i]) && ft_strstr(algoname[i], algo))
			return (algofunction[i]);
	usage_algo(algo);
	return (NULL);
}


static	char **get_av_from_standard_entry(void)
{
	char	buff[500];
	int		ret;

	ft_bzero(buff, sizeof(buff));
	ret = 0;
	if ((ret = read(0, buff, 500)) >= 0 && buff[ret - 1] == '\n')
	{
		buff[ret - 1] = '\0';
		return (ft_strsplit(buff, ' '));
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	int		option = 0;
	int		(*algo)(char**);
	int		ret = 1;

	ac == 1 ? ft_putstr("FT_SSL> ") : 0;
	do {
		if ((av = (ac == 1) ? get_av_from_standard_entry() : &(av[1])))
			if ((algo = select_algo(*av)))
				ret = algo(&(av[1]));
		ac == 1 ? ft_putstr("\rFT_SSL> ") : 0;
	} while (ac == 1 && av);
	
	ac == 1 ? free(av) : 0;
	return (0);
}
