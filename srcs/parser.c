/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 21:06:48 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int parse_element(t_info *info, char *line) {
  if (ft_strncmp(line, "NO ", 3) == 0)
    return (set_texture(&info->texture_path[NO], line + 3));
  if (ft_strncmp(line, "SO ", 3) == 0)
    return (set_texture(&info->texture_path[SO], line + 3));
  if (ft_strncmp(line, "WE ", 3) == 0)
    return (set_texture(&info->texture_path[WE], line + 3));
  if (ft_strncmp(line, "EA ", 3) == 0)
    return (set_texture(&info->texture_path[EA], line + 3));
  if (ft_strncmp(line, "F ", 2) == 0)
    return (set_rgb(info->floor, line + 2));
  if (ft_strncmp(line, "C ", 2) == 0)
    return (set_rgb(info->ceiling, line + 2));
  return (ERROR);
}

static void parse_elements(t_info *info, char *filename) {
  char *buf;
  char **file_contents;
  int fd;
  int i;

  fd = safe_open(filename);
  buf = read_file(fd);
  file_contents = ft_split(buf, "\n");
  free(buf);
  i = -1;
  while (file_contents[++i] && !is_map_content(file_contents[i])) {
    if (parse_element(info, file_contents[i]) == ERROR)
    {
      ft_allfree((void *)file_contents);
      exit(print_error("Invalid file content"));
    }
  }
  ft_allfree((void *)file_contents);
  if (!has_all_element(info))
    exit(print_error("not enough elements"));
  close(fd);
}

static void  check_map(char **map, int **visited, int x, int y)
{
  if (x == -1 || y == -1 || map[x] == NULL || map[x][y] == '\0')
    exit(print_error("not closed map"));
  if (map[x][y] == '1' || visited[x][y] == 1)
    return ;
  visited[x][y] = 1;
  check_map(map, visited, x - 1, y);
  check_map(map, visited, x + 1, y);
  check_map(map, visited, x, y - 1);
  check_map(map, visited, x, y + 1);
}

static void parse_map(t_info *info, char *filename) {
  int	  fd;
  int  **visited;

  fd = safe_open(filename);
  if (check_map_charset(fd) == ERROR)
    exit(print_error("Invalid map content"));
  close(fd);
  fd = safe_open(filename);
  info->map = get_map_array(fd);
  if (!info->map)
    exit(print_error("Map content not found"));
  set_player(info);
  visited = get_visited(info->map);
  check_map(info->map, visited, info->player.pos_x, info->player.pos_y);
  ft_allfree((void *)visited);
  close(fd);
}

void parse_file(t_info *info, char *filename) {
  if (!is_cub_file(filename))
    exit(print_error("Invalid file extension"));
  parse_elements(info, filename);
  parse_map(info, filename);
}
