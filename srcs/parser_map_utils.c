/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:56:35 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 14:40:26 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static char	*get_map_line(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line || (*line != '\n' && is_map_content(line)))
			break ;
		free(line);
	}
	return (line);
}

static void	set_player_direction(t_info *info, char dir)
{
	if (dir == 'N')
	{
		info->player.dir_x = -1;
		info->player.dir_y = 0;
	}
	else if (dir == 'S')
	{
		info->player.dir_x = 1;
		info->player.dir_y = 0;
	}
	else if (dir == 'E')
	{
		info->player.dir_x = 0;
		info->player.dir_y = 1;
	}
	else if (dir == 'W')
	{
		info->player.dir_x = 0;
		info->player.dir_y = -1;
	}
}

void	check_map_charset(char *filename)
{
	int		fd;
	char	*line;

	fd = safe_open(filename);
	line = get_map_line(fd);
	if (!line)
		exit(print_error("Map content not exists"));
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n' || !is_map_content(line))
			exit(print_error("Invalid map content"));
		free(line);
	}
	close(fd);
}

char	**get_map(char *filename)
{
	int		fd;
	char	*first_line_of_map;
	char	*remaining_line_of_map;
	char	*map;
	char	**ret;

	fd = safe_open(filename);
	first_line_of_map = get_map_line(fd);
	if (!first_line_of_map)
		exit(print_error("Map content not found"));
	remaining_line_of_map = read_file(fd);
	map = ft_strjoin(first_line_of_map, remaining_line_of_map);
	free(first_line_of_map);
	free(remaining_line_of_map);
	ret = ft_split(map, "\n");
	free(map);
	close(fd);
	return (ret);
}

void	set_player(t_info *info)
{
	int	x;
	int	y;
	int	num_of_player;

	x = -1;
	num_of_player = 0;
	while (info->map[++x])
	{
		y = -1;
		while (info->map[x][++y])
		{
			if (ft_strchr("NSEW", info->map[x][y]))
			{
				info->player.pos_x = x + 0.5;
				info->player.pos_y = y + 0.5;
				num_of_player++;
				set_player_direction(info, info->map[x][y]);
				info->map[x][y] = '0';
			}
		}
	}
	if (!num_of_player)
		exit(print_error("Player not exists"));
	if (num_of_player > 1)
		exit(print_error("Too many players"));
}
