/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/25 05:00:39 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

static int	parse_element(t_info *info, char *content)
{
	if (ft_strncmp(content, "NO ", 3) == 0)
		return (set_texture(&info->texture[NO], content + 3));
	if (ft_strncmp(content, "SO ", 3) == 0)
		return (set_texture(&info->texture[SO], content + 3));
	if (ft_strncmp(content, "WE ", 3) == 0)
		return (set_texture(&info->texture[WE], content + 3));
	if (ft_strncmp(content, "EA ", 3) == 0)
		return (set_texture(&info->texture[EA], content + 3));
	if (ft_strncmp(content, "F ", 2) == 0)
		return (set_rgb(info->floor, content + 2));
	if (ft_strncmp(content, "C ", 2) == 0)
		return (set_rgb(info->ceilling, content + 2));
	return (ERROR);
}

int		parse_elements(t_info *info, char **file_contents, int *idx)
{
	while (file_contents[*idx] && !is_map_content(file_contents[*idx]))
	{
		if (parse_element(info, file_contents[*idx]) == ERROR)
			exit(print_error("Invalid file content"));
		(*idx)++;
	}
	if (!has_all_element(info))
		return (ERROR);
	return (0);
}

int	parse_map(t_info *info, char **file_contents)
{
	int	size;
	int	i;

	size = 0;
	while (file_contents[size])
		size++;
	info->map = malloc(sizeof(char *) * (size + 1));
	if (!info->map)
		return (ERROR);
	i = -1;
	while (++i < size)
		info->map[i] = ft_strdup(file_contents[i]);
	info->map[i] = NULL;
	return (0);
}

int	parse_file_contents(t_info *info, char **file_contents)
{
	int	file_contents_idx;

	file_contents_idx = 0;
	if (parse_elements(info, file_contents, &file_contents_idx) == ERROR)
		return (ERROR);
	if (parse_map(info, file_contents + file_contents_idx) == ERROR)
		return (ERROR);
	return (0);
}

void	parse_file(t_info *info, char *filename)
{
	char	**file_contents;

	if (!is_cub_file(filename))
		exit(print_error("Invalid file extension"));
	file_contents = read_file(filename);
	if (!file_contents)
		exit(print_perror());
	if (parse_file_contents(info, file_contents) == ERROR)
		exit(print_error("Invalid file content"));
	ft_allfree(file_contents);
}
