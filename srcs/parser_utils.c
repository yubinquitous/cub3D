/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:54:48 by yoson             #+#    #+#             */
/*   Updated: 2022/12/27 13:41:07 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"

char	*read_file(int fd)
{
	char	*line;
	char	*join;
	char	*temp;

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
	return (join);
}

int	is_valid_element(char *line)
{
	size_t	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ' || !ft_isprint(line[i]))
			return (FALSE);
	}
	return (TRUE);
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

int	is_map_content(char *line)
{
	const char	*charset = " 01NSEW\n";

	if (ft_isalpha(*line))
		return (FALSE);
	while (*line)
	{
		if (!ft_strchr(charset, *line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

int	**get_visited(char **map)
{
	int		**ret;
	int		size;
	int		i;

	size = 0;
	while (map[size])
		size++;
	ret = safe_malloc(sizeof(int *) * (size + 1));
	i = 0;
	while (i < size)
	{
		ret[i] = ft_calloc(ft_strlen(map[i]), sizeof(int));
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
