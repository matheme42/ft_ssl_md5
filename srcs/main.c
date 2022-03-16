/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:03:48 by matheme           #+#    #+#             */
/*   Updated: 2022/03/15 20:14:45 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"



static void	(*select_algo(char *algo))(char **)
{

	char	*algoname[] = {"md5", "sha256", "whirlpool", NULL};
	void	(*algofunction[])(char **) = {&md5, &sha256, &whirlpool, NULL};
	int		i;

	i = -1;
	while (algoname[++i])
		if (!ft_strncmp_case_unsensitive(algo, algoname[i], ft_strlen(algoname[i])))
			return (algofunction[i]);
	usage_algo(algo);
	return (NULL);
}

int		main(int ac, char **av)
{
	int		option = 0;
	void	(*algo)(char**);
	char	buff[100];

	if (ac == 1)
		return (usage());
	size_t size = 0;

	if (!(algo = select_algo(av[1])))
		return (0);
	algo(&(av[2]));
	return (0);
}
