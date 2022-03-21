/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:33:00 by matheme           #+#    #+#             */
/*   Updated: 2022/03/21 11:59:09 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int    try_get_fd_from_string(char *s)
{
    int fd;
    if ((fd = open(s, O_RDONLY)) < 0)
    {
		ft_printf("unable to open the file name '%s'\n", s);
        return (-1);
    }
    if (read(fd, NULL, 0) < 0)
    {
		ft_printf("ret");
		ft_printf("unable to read the file '%s'\n", s);
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

	if (size == NULL || fd < 0)
		return (NULL);
	*size = 0;
	file = NULL;
	ft_bzero(buff, sizeof(buff));
	while((ret = read(fd, buff, 100)) > 0)
	{
		if (!(newfile = ft_strnjoin(file, buff, *size, ret)))
			return (NULL);
		if (file != NULL)
			free(file);
		file = newfile;
		newfile = NULL;
		ft_bzero(buff, sizeof(buff));
		*size += ret;
	}
	if (file == NULL && ret >= 0)
		return(ft_strdup("\0"));
	if (ret < 0)
		ft_printf("unable to read from fd %d\n", fd);
	return (file);
}

static char	*get_file_from_manual_standard_entry(size_t *size)
{
	char	buff[100];
	char	*file;
	char	*newfile;
	int		ret;

	if (size == NULL)
		return (NULL);
	*size = 0;
	file = NULL;
	ft_bzero(buff, sizeof(buff));
	while((ret = read(0, buff, 100)) > 0)
	{
		if (!(newfile = ft_strnjoin(file, buff, *size, ret)))
			return (NULL);
		if (file != NULL)
			free(file);
		file = newfile;
		newfile = NULL;
		ft_bzero(buff, sizeof(buff));
		*size += ret;
		if (file[*size - 1] != '\n')
			break;
	}
	if (file == NULL && ret >= 0)
		return(ft_strdup("\0"));
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
	if (select(1, &readfds, NULL, NULL, &timeout))
		return (get_file_from_fd(0, size));
	else if (force)
		return (get_file_from_manual_standard_entry(size));
    return (NULL);
}