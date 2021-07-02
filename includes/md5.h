/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:04:14 by matheme           #+#    #+#             */
/*   Updated: 2021/07/01 17:30:47 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef struct  g_h {
    int h0;
    int h1;
    int h2;
    int h3;
}               t_h;



#endif