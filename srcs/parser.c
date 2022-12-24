/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/24 16:53:34 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "cub3d.h"

static int	is_valid_line(char *line)
{
	char	**splitted;
	int		color;
	int		i;
	
	if (!line || ft_strchr(line, ' ') || has_continuous_char(line, ','))
		return (ERROR);
	splitted = ft_split(line, ',');
	if (!splitted)
		return (ERROR);
	if (find_strarr_len(splitted) != 3)
		return (ft_free(splitted));
	i = -1;
	while (splitted[++i])
	{
		if (!is_only_digit(splitted[i]))
			return (ft_free(splitted));
		color = ft_atoi(splitted[i]);
		if (color == ERROR || color > 255)
			return (ft_free(splitted));
	}
	ft_free(splitted);
	return (TRUE);
}

static int	set_color(int color[], char *line)
{
	char	*trimmed;
	char	**splitted;
	int		i;

	trimmed = ft_strtrim(line, " ");
	if (!is_valid_line(trimmed))
	{
		free(trimmed);
		return (ERROR);
	}
	splitted = ft_split(trimmed, ',');
	if (!splitted)
		return (ERROR);
	i = -1;
	while (splitted[++i])
		color[i] = ft_atoi(splitted[i]);
	free(trimmed);
	ft_free(splitted);
	return (0);
}

int	set_map(char ***map, char *line, int fd)
{
	
}

static int	parse_line(t_info *info, char *line, int fd)
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
		return (set_color(info->floor, line + 2));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (set_color(info->ceilling, line + 2));
	if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		return (0);
	if (is_map_line(line))
		return (set_map(&info->map, line, fd));
	else
		return (ERROR);
}

void	parse_file(t_info *info, char *filename)
{
	int		fd;
	char	*line;

	if (!is_cub_file(filename))
		exit(print_error("Invalid file extension"));
	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		exit(print_perror());
	while (1)
	{
		line = get_next_line(fd);
		if (errno)
			exit(print_perror());
		if (!line)
			break ;
		if (parse_line(info, line, fd) == ERROR)
			exit(print_error("Invalid file content"));
		free(line);
	}
	close(fd);
}
