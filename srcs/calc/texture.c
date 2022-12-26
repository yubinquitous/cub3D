/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:26 by yubin             #+#    #+#             */
/*   Updated: 2022/12/26 21:57:28 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void draw_ceiling(t_info *info, t_raycast *raycast, int x) {
  int y;

  y = -1;
  while (++y < raycast->draw_start)
  {
    info->game.buf[y][x] = 0x00000000;
    info->game.buf[y][x] += info->ceiling[0] << 16;
    info->game.buf[y][x] += info->ceiling[1] << 8;
    info->game.buf[y][x] += info->ceiling[2];
  }
}

static void draw_floor(t_info *info, t_raycast *raycast, int x) {
  int y;

  y = raycast->draw_end - 1;
  while (++y < WINDOW_HEIGHT)
  {
    info->game.buf[y][x] = 0x00000000;
    info->game.buf[y][x] += info->floor[0] << 16;
    info->game.buf[y][x] += info->floor[1] << 8;
    info->game.buf[y][x] += info->floor[2];
  }
}

static void coordinate_texture(t_info *info, t_raycast *raycast, int x,
                               int texNum, int texX) {
  double step;
  double texPos;
  int texY;
  int y;
  int color;

  step = 1.0 * TEX_HEIGHT / raycast->line_height;
  texPos =
      (raycast->draw_start - WINDOW_HEIGHT / 2. + raycast->line_height / 2.) *
      step;
  draw_ceiling(info, raycast, x);
  draw_floor(info, raycast, x);
  y = raycast->draw_start - 1;
  while (++y < raycast->draw_end) {
    texY = (int)texPos & (TEX_HEIGHT - 1);
    texPos += step;
    color = info->game.texture[texNum][TEX_HEIGHT * texY + texX];
    if (raycast->side == 1)
      color = (color >> 1) & 8355711;
    info->game.buf[y][x] = color;
  }
}

void calc_texture(t_info *info, t_raycast *raycast, int x) {
  int texNum;
  double wallX;
  int texX;

  texNum = info->map[raycast->map_x][raycast->map_y] - '0' - 1;
  if (raycast->side == 0)
    wallX = info->player.pos_y + raycast->perp_wall_dist * raycast->ray_dir_y;
  else
    wallX = info->player.pos_x + raycast->perp_wall_dist * raycast->ray_dir_x;
  wallX -= floor(wallX);
  texX = (int)(wallX * (double)TEX_WIDTH);
  if (raycast->side == 0 && raycast->ray_dir_x > 0)
    texX = TEX_WIDTH - texX - 1;
  if (raycast->side == 1 && raycast->ray_dir_y < 0)
    texX = TEX_WIDTH - texX - 1;
  coordinate_texture(info, raycast, x, texNum, texX);
}