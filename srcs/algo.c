/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:39:15 by matheme           #+#    #+#             */
/*   Updated: 2021/05/17 17:25:58 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char **get_algo(int *ac, char **av, char **algo)
{
	char** algos;

	if (*ac == 1)
	{
		usage();
		exit(1);
	}
	*ac -= 1;
	algos = ft_strsplit(LIST_ALGO, ' ');
	while (*algos != NULL)
	{
		if (!ft_strncmp_case_unsensitive(av[1], *algos, MAX_ALGO_NAME_SIZE))
		{
			*algo = av[1];
			break ;
		}
		algos = &algos[1];
	}
	if (*algo == NULL)
	{
		usage_algo(av[1]);
		exit(1);
	}
	return (&av[1]);
}
