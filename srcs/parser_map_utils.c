/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:11:06 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/12/26 01:46:08 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3d.h"

static char *get_map_line(int fd)
{
    char    *line;

    while (1)
    {
        line = get_next_line(fd);
        if (!line || (*line != '\n' && is_map_content(line)))
            break ;
        free(line);
    }
    return (line);
}

int check_map_charset(int fd)
{
    char    *line;

    line = get_map_line(fd);
    if (!line)
        return (ERROR);
    free(line);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (*line == '\n' || !is_map_content(line))
        {
            free(line);
            return (ERROR);
        }
        free(line);
    }
    return (0);
}

char    **get_map_array(int fd)
{
    char	*first_line;
	char	*buf;
	char	*join;
    char    **map;

    first_line = get_map_line(fd);
    if (!first_line)
        return (NULL);
	buf = read_file(fd);
	join = ft_strjoin(first_line, buf);
	free(first_line);
	free(buf);
	map = ft_split(join, "\n");
	free(join);
    return (map);
}