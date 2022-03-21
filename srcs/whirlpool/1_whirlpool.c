/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_whirlpool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:27:49 by matheme           #+#    #+#             */
/*   Updated: 2022/03/18 16:39:44 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "whirlpool.h"

int whirlpool(char **av)
{
    int         option;
    t_option    complexe;
    size_t      file_size;
    char        *str_file;
    char        *hash;

    av = whirlpool_get_option(av, &option, &complexe);

    if (H || !av)
        return (whirlpool_usage());

    if ((str_file = get_file_from_standard_entry(&file_size, P || (!*av && !complexe.s))))
    {
        hash = whirlpool_algo(option, file_size, str_file);
        whirlpool_output(!P ? "stdin" : str_file, hash, option);
        free(str_file);
        free(hash);
    }

    if (complexe.s)
    {
        file_size = ft_strlen(complexe.s);
        hash = whirlpool_algo(option, file_size, complexe.s);
        whirlpool_output(complexe.s, hash, option);
        free(hash);
    }
    
    while (*av)
    {
        if ((str_file = get_file_from_fd(try_get_fd_from_string(*av), &file_size)))
        {
            hash = whirlpool_algo(option, file_size, str_file);
            whirlpool_output(*av, hash, option);
            free(str_file);
            free(hash);
        }
        av = &av[1];
    }
    return (0);
}
