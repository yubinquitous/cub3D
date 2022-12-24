/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/24 18:09:06 by son-yeong-w      ###   ########.fr       */
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

static int	parse_line(t_info *info, char *line)
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
	else
		return (ERROR);
}

int	has_all_element(t_info *info)
{
	int	i;

	i = -1;
	while (++i < sizeof(info->texture) / sizeof(char *))
	{
		if (!info->texture[i])
			return (FALSE);
	}
	i = -1;
	while (++i < sizeof(info->floor) / sizeof(int))
	{
		if (info->floor[i] == -1)
			return (FALSE);
	}
	i = -1;
	while (++i < sizeof(info->ceilling) / sizeof(int))
	{
		if (info->ceilling[i] == -1)
			return (FALSE);
	}
	return (TRUE);
}

int		parse_element(t_info *info, char **content)
{
	int	i;

	if (content[0] == NULL)
	{
		free(content);
		return (ERROR);
	}
	if (!content[0][0] == '\0')
		return (ft_free(content));
	i = -1;
	while (content[++i] && !is_map_content(content[i]))
	{
		if (parse_line(info, content[i]) == ERROR)
			exit(print_error("Invalid file content"));
	}
	if (!has_all_element(info))
		return (ERROR);
	return (i);
}

char	**read_file(t_info *info, char *filename)
{
	char	*line;
	char	*join;
	char	*temp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == ERROR)
		return (NULL);
	join = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = join;
		join = ft_strjoin(join, line);
		free(temp);
		free(line);
	}
	close(fd);
	return (ft_split(join, '\n'));
}

int	parse_map(t_info *info, char **content)
{
	int	size;
	int	i;

	size = 0;
	while (content[size])
		size++;
	info->map = malloc(sizeof(char *) * size);
	if (!info->map)
		return (ERROR);
	i = -1;
	while (++i < size)
		info->map[i] = content[i];
	info->map[i] = NULL;
	return (0);
}

void	parse_file(t_info *info, char *filename)
{
	char	**content;
	int		map_idx;

	if (!is_cub_file(filename))
		exit(print_error("Invalid file extension"));
	content = read_file(info, filename);
	if (!content)
		exit(print_perror());
	map_idx = parse_element(info, content);
	if (map_idx == ERROR || parse_map(info, content + map_idx) == ERROR)
		exit(print_error("Invalid file content"));
	ft_free(content);
}
