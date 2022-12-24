/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:42:51 by yoson             #+#    #+#             */
/*   Updated: 2022/12/23 21:09:04 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int	has_continuous_char(char *str, char c)
{
	while (*str)
	{
		str = ft_strchr(str, c);
        if (!str)
            break ;
		if (*(++str) == c)
			return (TRUE);
	}
    return (FALSE);
}

char    *skip_blank(char *str)
{
    while (*str)
    {
        if (*str != ' ')
            return (str);
        str++;
    }
    return (NULL);
}

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

int ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (ERROR);
}