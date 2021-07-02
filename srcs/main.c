/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:03:48 by matheme           #+#    #+#             */
/*   Updated: 2021/05/17 17:26:15 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*get_file_from_fd(const int fd, size_t *size)
{
	char	buff[100];
	char	*file;
	char	*newfile;
	int		ret;

	*size = 0;
	file = NULL;
	ft_bzero(buff, sizeof(buff));
	while((ret = read(fd, buff, 100)))
	{
		newfile = ft_strnjoin(file, buff, *size, ret);
		if (file != NULL)
			free(file);
		file = newfile;
		newfile = NULL;
		ft_bzero(buff, sizeof(buff));
		*size += ret;
	}
	return (file);
}

void algo_selector(char *algo, char *file, unsigned long size, char *name)
{
	if (!ft_strncmp_case_unsensitive(algo, "md5", MAX_ALGO_NAME_SIZE))
		md5(file, size, name);
}

int		main(int ac, char **av)
{
	int				option = 0;
	char			*algo = NULL;
	char			*file = NULL;
	size_t			size = 0;

	av = get_algo(&ac, av, &algo);
	av = get_option(ac - 1, &av[1], &option);
	if (*av == NULL) {
		file = get_file_from_fd(0, &size);
		algo_selector(algo, file, size, "");
	}
	while (*av != NULL)
	{
		int fd;
		if ((fd = open(*av, O_RDONLY)) < 0)
		{
			ft_putstr(*av);
			ft_putstr(": No such file or directory\n");
			av = &av[1];
			continue ;
		}
		file = get_file_from_fd(fd, &size);
		close(fd);
		algo_selector(algo, file, size, *av);
		av = &av[1];
	}
	if (file != NULL)
		free(file);
	return (0);
}
