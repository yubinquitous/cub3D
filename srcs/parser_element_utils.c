/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_element_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 04:56:23 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/12/28 17:44:11 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_valid_rgb(char *rgb)
{
	if (!is_valid_element(rgb)
		|| has_continuous_char(rgb, ',')
		|| rgb[0] == ','
		|| rgb[ft_strlen(rgb) - 1] == ',')
		return (FALSE);
	return (TRUE);
}

static int	check_rgb(char *rgb)
{
	char	**rgb_splitted;
	int		color_depth;
	int		i;

	if (!is_valid_rgb(rgb))
		return (ERROR);
	rgb_splitted = ft_split(rgb, ",");
	if (find_strarr_len(rgb_splitted) != 3)
		return (ft_allfree((void *)rgb_splitted));
	i = -1;
	while (rgb_splitted[++i])
	{
		if (!has_only_digit(rgb_splitted[i]))
			return (ft_allfree((void *)rgb_splitted));
		color_depth = ft_atoi(rgb_splitted[i]);
		if (color_depth > 255)
			return (ft_allfree((void *)rgb_splitted));
	}
	ft_allfree((void *)rgb_splitted);
	return (0);
}

void	set_rgb(int dest[], char *line)
{
	char	*rgb;
	char	**rgb_splitted;
	int		i;

	if (*dest != -1)
		exit(print_error("duplicate elements"));
	rgb = ft_strtrim(line, " ");
	if (check_rgb(rgb) == ERROR)
		exit(print_error("Invalid elements"));
	rgb_splitted = ft_split(rgb, ",");
	i = -1;
	while (rgb_splitted[++i])
		dest[i] = ft_atoi(rgb_splitted[i]);
	free(rgb);
	ft_allfree((void *)rgb_splitted);
}

void	set_texture(char **dest, char *line)
{
	char	*texture_path;

	if (*dest)
		exit(print_error("duplicate elements"));
	texture_path = ft_strtrim(line, " ");
	if (*texture_path == '\0' || !is_valid_element(texture_path))
		exit(print_error("Invalid element"));
	*dest = texture_path;
}

int	has_all_elements(t_info *info)
{
	size_t	i;

	i = -1;
	while (++i < sizeof(info->texture_path) / sizeof(char *))
	{
		if (!info->texture_path[i])
			return (FALSE);
	}
	i = -1;
	while (++i < sizeof(info->floor) / sizeof(int))
	{
		if (info->floor[i] == -1)
			return (FALSE);
	}
	i = -1;
	while (++i < sizeof(info->ceiling) / sizeof(int))
	{
		if (info->ceiling[i] == -1)
			return (FALSE);
	}
	return (TRUE);
}
