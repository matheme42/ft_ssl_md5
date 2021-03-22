/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:04:46 by matheme           #+#    #+#             */
/*   Updated: 2021/03/18 14:34:29 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
int main(int argc, char **argv) {
 
    if (argc < 2) {
        printf("usage: %s 'string'\n", argv[0]);
        return 1;
    }
 
    char *msg = argv[1];
    size_t len = strlen(msg);

    md5(msg, len);

    return (0);
}