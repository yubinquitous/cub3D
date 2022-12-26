/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 01:49:18 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"

static int	parse_element(t_info *info, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture(&info->texture[NO], line + 3));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture(&info->texture[SO], line + 3));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture(&info->texture[WE], line + 3));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture(&info->texture[EA], line + 3));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (set_rgb(info->floor, line + 2));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (set_rgb(info->ceilling, line + 2));
	return (ERROR);
}

static int		parse_elements(t_info *info, char *filename)
{
	char	*buf;
	char	**file_contents;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		exit(print_perror());
	buf = read_file(fd);
	file_contents = ft_split(buf, "\n");
	free(buf);
	i = -1;
	while (file_contents[++i] && !is_map_content(file_contents[i]))
	{
		if (parse_element(info, file_contents[i]) == ERROR)
			return (ft_allfree(file_contents));
	}
	ft_allfree(file_contents);
	if (!has_all_element(info))
		return (ERROR);
	close(fd);
	return (0);
}

static int	parse_map(t_info *info, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		exit(print_perror());
	if (check_map_charset(fd) == ERROR)
		return (ERROR);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		exit(print_perror());
	info->map = get_map_array(fd);
	// if (!info->map || !is_valid_map(info->map)) 구현해야함
	// 	return (ERROR);					
	close(fd);
	return (0);
}

void	parse_file(t_info *info, char *filename)
{
	if (!is_cub_file(filename))
		exit(print_error("Invalid file extension"));
	if (parse_elements(info, filename) == ERROR || parse_map(info, filename) == ERROR)
		exit(print_error("Invalid file content"));
}
