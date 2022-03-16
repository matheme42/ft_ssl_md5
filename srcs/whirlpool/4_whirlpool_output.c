/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_whirlpool_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:07:48 by matheme           #+#    #+#             */
/*   Updated: 2022/03/11 17:43:49 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whirlpool.h"

void whirlpool_output(char *file_name, char *hash, int option)
{
    !Q && !R ? ft_printf("whirlpool(%s)= ", file_name) : 0;
    ft_printf("%s", hash);
    !Q && R ? ft_printf("  %s", file_name) : 0;
    ft_putchar('\n');
}