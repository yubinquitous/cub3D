/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:42:51 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 00:39:31 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int find_strarr_len(char **str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);   
}

int is_only_digit(char *str)
{
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (FALSE);
        str++;
    }
    return (TRUE);
}

int ft_allfree(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (ERROR);
}