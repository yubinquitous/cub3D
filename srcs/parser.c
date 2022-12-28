/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/27 13:42:29 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	check_map(char **map, int **visited, int x, int y)
{
	if (x == -1 || y == -1 || map[x] == NULL || map[x][y] == '\0')
		exit(print_error("not closed map"));
	if (map[x][y] == '1' || visited[x][y] == 1)
		return ;
	visited[x][y] = 1;
	check_map(map, visited, x - 1, y);
	check_map(map, visited, x + 1, y);
	check_map(map, visited, x, y - 1);
	check_map(map, visited, x, y + 1);
}

static void	parse_map(t_info *info, char *filename)
{
	int	**visited;

	check_map_charset(filename);
	info->map = get_map(filename);
	set_player(info);
	visited = get_visited(info->map);
	check_map(info->map, visited, info->player.pos_x, info->player.pos_y);
	ft_allfree((void *)visited);
}

static void	parse_element(t_info *info, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		set_texture(&info->texture_path[NO], line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		set_texture(&info->texture_path[SO], line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_texture(&info->texture_path[WE], line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_texture(&info->texture_path[EA], line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		set_rgb(info->floor, line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		set_rgb(info->ceiling, line + 2);
	else
		exit(print_error("Invalid file content"));
}

static void	parse_elements(t_info *info, char *filename)
{
	char	*buf;
	char	**file_contents;
	int		fd;
	int		i;

	fd = safe_open(filename);
	buf = read_file(fd);
	file_contents = ft_split(buf, "\n");
	free(buf);
	i = -1;
	while (file_contents[++i] && !is_map_content(file_contents[i]))
		parse_element(info, file_contents[i]);
	if (!has_all_elements(info))
		exit(print_error("not enough elements"));
	ft_allfree((void *)file_contents);
	close(fd);
}

void	parse_file(t_info *info, char *filename)
{
	if (!is_cub_file(filename))
		exit(print_error("Invalid file extension"));
	parse_elements(info, filename);
	parse_map(info, filename);
}
