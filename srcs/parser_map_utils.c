/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:11:06 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/12/26 15:20:18 by yubin            ###   ########.fr       */
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

static void set_player_direction(t_info *info, char dir)
{
    if (dir == 'N')
    {
        info->player.dir_x = 0;
        info->player.dir_y = 1;
    }
    else if (dir == 'S')
    {
        info->player.dir_x = 0;
        info->player.dir_y = -1;
    }
    else if (dir == 'E')
    {
        info->player.dir_x = 1;
        info->player.dir_y = 0;
    }
    else if (dir == 'W')
    {
        info->player.dir_x = -1;
        info->player.dir_y = 0;
    }
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

void set_player(t_info *info)
{
    int x;
    int y;
    int player_count;

    x = -1;
    y = -1;
    player_count = 0;
    while (info->map[++y])
    {
        while (info->map[y][++x])
        {
            if (ft_strchr("NSEW", info->map[y][x]))
            {
                info->player.pos_x = x;
                info->player.pos_y = y;
                player_count++;
                set_player_direction(info, info->map[y][x]);
            }
        }
    }
    if (player_count == 0)
        exit(print_error("Player not exists"));
    if (player_count > 1)
        exit(print_error("Too many players"));
}