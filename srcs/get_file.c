/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:33:00 by matheme           #+#    #+#             */
/*   Updated: 2022/03/11 17:37:29 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int    try_get_fd_from_string(char *s)
{
    int fd;

    if ((fd = open(s, O_RDONLY)) < 0)
    {
        usage_open(s);
        return (-1);
    }
    if (read(fd, NULL, 0) < 0)
    {
        usage_read(s);
        return (-1);
    }
    return (fd);
}

char	*get_file_from_fd(const int fd, size_t *size)
{
	char	buff[100];
	char	*file;
	char	*newfile;
	int		ret;

	if (fd < 0)
	{
		return (NULL);
	}
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

char	*get_file_from_standard_entry(size_t *size, int force)
{
	fd_set          readfds;
	fd_set          savefds = readfds;
	struct timeval  timeout;

	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);
	ft_bzero(&timeout, sizeof(timeout));

	if (select(1, &readfds, NULL, NULL, &timeout) || force)
		return (get_file_from_fd(0, size));
    return (NULL);
}