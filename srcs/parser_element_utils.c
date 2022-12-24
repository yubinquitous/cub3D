/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_element_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 04:56:23 by son-yeong-w       #+#    #+#             */
/*   Updated: 2022/12/25 05:15:30 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

static int	has_continuous_comma(char *str)
{
	while (*str)
	{
		str = ft_strchr(str, ',');
        if (!str)
            break ;
		if (*(++str) == ',')
			return (TRUE);
	}
    return (FALSE);
}

int	validate_rgb(char *rgb)
{
	char	**rgb_splitted;
	int		color_depth;
	int		i;
	
	if (!is_valid_content(rgb) || has_continuous_comma(rgb))
		return (ERROR);
	rgb_splitted = ft_split(rgb, ",");
	if (!rgb_splitted)
		return (ERROR);
	if (find_strarr_len(rgb_splitted) != 3)
		return (ft_allfree(rgb_splitted));
	i = -1;
	while (rgb_splitted[++i])
	{
		if (!is_only_digit(rgb_splitted[i]))
			return (ft_allfree(rgb_splitted));
		color_depth = ft_atoi(rgb_splitted[i]);
		if (color_depth == ERROR || color_depth > 255)
			return (ft_allfree(rgb_splitted));
	}
	ft_allfree(rgb_splitted);
	return (0);
}

int	set_rgb(int dest[], char *content)
{
	char	*rgb;
	char	**rgb_splitted;
	int		i;

	rgb = ft_strtrim(content, " ");
	if (!rgb || validate_rgb(rgb) == ERROR)
	{
		free(rgb);
		return (ERROR);
	}
	rgb_splitted = ft_split(rgb, ",");
	if (!rgb_splitted)
		return (ERROR);
	i = -1;
	while (rgb_splitted[++i])
		dest[i] = ft_atoi(rgb_splitted[i]);
	free(rgb);
	ft_allfree(rgb_splitted);
	return (0);
}

int	set_texture(char **dest, char *content)
{
	char	*texture_path;

	texture_path = ft_strtrim(content, " ");
	if (!texture_path || !is_valid_content(texture_path))
		return (ERROR);
	*dest = texture_path;
	return (0);
}

int	has_all_element(t_info *info)
{
	size_t	i;

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