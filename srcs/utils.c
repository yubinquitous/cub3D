/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:42:51 by yoson             #+#    #+#             */
/*   Updated: 2022/12/27 02:24:26 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>

int find_strarr_len(char **str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);   
}

int has_only_digit(char *str)
{
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (FALSE);
        str++;
    }
    return (TRUE);
}

int ft_allfree(void **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
        free(ptr[i++]);
    free(ptr);
    return (ERROR);
}

int safe_open(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == ERROR)
        exit(print_strerror(filename));
    return (fd);
}
