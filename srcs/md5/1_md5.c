/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_md5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:29:16 by matheme           #+#    #+#             */
/*   Updated: 2022/03/18 16:55:22 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "md5.h"

int md5(char **av)
{
    int         option;
    t_option    complexe;
    size_t      file_size;
    char        *str_file;
    char        *hash;



    av = md5_get_option(av, &option, &complexe);

    if (H || !av)
        return (md5_usage());

    if ((str_file = get_file_from_standard_entry(&file_size, P || (!*av && !complexe.s))))
    {
        hash = md5_algo(option, file_size, str_file);
        md5_output(!P ? "stdin" : str_file, hash, option);
        free(str_file);
        free(hash);
    }

    if (complexe.s)
    {
        file_size = ft_strlen(complexe.s);
        hash = md5_algo(option, file_size, complexe.s);
        md5_output(complexe.s, hash, option);
        free(hash);
    }

    while (*av)
    {
        if ((str_file = get_file_from_fd(try_get_fd_from_string(*av), &file_size)))
        {
            hash = md5_algo(option, file_size, str_file);
            md5_output(*av, hash, option);
            free(str_file);
            free(hash);
        }
        av = &av[1];
    }
    return (0);
}
