/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:54:48 by yoson             #+#    #+#             */
/*   Updated: 2022/12/24 15:26:38 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "cub3d.h"

int	set_texture(char **texture, char *line)
{
	char	*texture_path;

	texture_path = ft_strtrim(line, " ");
	if (!texture_path || ft_strchr(texture_path, ' '))
		return (ERROR);
	*texture = texture_path;
	return (0);
}

int	parse_error_handler(char *filename)
{
	if (errno)
		exit(print_perror(NULL));
	exit(print_error(filename, "Invalid file content"));
}

int	is_cub_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	filename = filename + len - 4;
	if (ft_strncmp(filename, ".cub", ft_strlen(filename)) != 0)
		return (FALSE);
	return (TRUE);
}

int is_map_line(char *line)
{
    const char  *map_set = " \n012NSEW";

    if (*line == '\0')
        return (FALSE);
    while (*line)
    {
        if (!ft_strchr(map_set, *line))
            return (FALSE);
        line++;
    }
    return (TRUE);
}