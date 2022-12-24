/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:54:48 by yoson             #+#    #+#             */
/*   Updated: 2022/12/25 05:09:40 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"

char	**read_file(char *filename)
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
	return (ft_split(join, "\n"));
}

int	is_valid_content(char *content)
{
	size_t	i;

	i = -1;
	while (content[++i])
	{
		if (content[i] == ' ' || !ft_isprint(content[i]))
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
 
int is_map_content(char *line)
{
    const char  *charset = " 012NSEW";

    while (*line)
    {
        if (!ft_strchr(charset, *line))
            return (FALSE);
        line++;
    }
    return (TRUE);
}