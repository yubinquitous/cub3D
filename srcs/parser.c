/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:51:58 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 20:47:56 by yubin            ###   ########.fr       */
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

static int parse_elements(t_info *info, char *filename) {
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
      return (ft_allfree(file_contents));
  }
  ft_allfree(file_contents);
  if (!has_all_element(info))
    return (ERROR);
  close(fd);
  return (0);
}

// void  check_map(char **map, int x, int y)
// {
  
//   check_map(map, x - 1, y);
//   check_map(map, x + 1, y);
//   check_map(map, x, y - 1);
//   check_map(map, x, y + 1);
// }

static int parse_map(t_info *info, char *filename) {
  int fd;

  fd = safe_open(filename);
  info->map = get_map_array(fd);
  if (!info->map)
    return (ERROR);
  set_player(info);
  // check_map(info->map, info->player.pos_x, info->player.pos_y);
  close(fd);
  return (0);
}

void parse_file(t_info *info, char *filename) {
  if (!is_cub_file(filename))
    exit(print_error("Invalid file extension"));
  if (parse_elements(info, filename) == ERROR ||
      parse_map(info, filename) == ERROR)
    exit(print_error("Invalid file content"));
}
