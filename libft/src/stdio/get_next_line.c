/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:53:58 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/02 00:45:00 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_stdlib.h"
#include "../../include/ft_string.h"
#include "../../include/get_next_line.h"

static void	ft_get_line(t_line *line, char buf[])
{
	line->old_str = line->str;
	line->old_len = ft_strlen(line->old_str);
	line->new_len = ft_strcspn(buf, "\n");
	if (buf[line->new_len] == '\n')
	{
		line->lf = 1;
		line->new_len++;
	}
	line->str = ft_calloc(1, line->old_len + line->new_len + 1);
	if (line->str)
	{
		ft_memcpy(line->str, line->old_str, line->old_len);
		ft_memcpy(line->str + line->old_len, buf, line->new_len);
	}
	ft_free((void *)&line->old_str);
}

char	*get_next_line(int fd)
{
	t_line		line;
	static char	buf[BUF_SIZE + 1];

	if (BUF_SIZE <= 0)
		return (NULL);
	ft_memset(&line, 0, sizeof(line));
	line.str = ft_calloc(1, 1);
	if (!line.str)
		return (NULL);
	ft_get_line(&line, buf);
	while (!line.lf && line.str)
	{
		ft_memset(buf, 0, BUF_SIZE);
		line.read_cnt = read(fd, buf, BUF_SIZE);
		if (line.read_cnt == 0 && *line.str)
			return (line.str);
		if (line.read_cnt <= 0)
			return (ft_free((void *)&line.str));
		ft_get_line(&line, buf);
	}
	ft_memcpy(buf, buf + line.new_len, BUF_SIZE - line.new_len + 1);
	return (line.str);
}
