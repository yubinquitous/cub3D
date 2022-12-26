#include "../../includes/raycasting.h"

static void coordinate_texture(t_info *info, t_raycast *raycast, int x,
                               int texNum, int texX) {
  double step;
  double texPos;
  int texY;
  int y;

  step = 1.0 * TEX_HEIGHT / raycast->line_height;
  texPos =
      (raycast->draw_start - WINDOW_HEIGHT / 2. + raycast->line_height / 2.) *
      step;
  y = raycast->draw_start - 1;
  while (++y < raycast->draw_end) {
    texY = (int)texPos & (TEX_HEIGHT - 1);
    texPos += step;
    int color = info->texture[texNum][TEX_HEIGHT * texY + texX];
    if (raycast->side == 1)
      color = (color >> 1) & 8355711;
    info->buf[y][x] = color;
  }
}

void calc_texture(t_info *info, t_raycast *raycast, int x) {
  int texNum;
  double wallX;
  int texX;

  texNum = info->map[raycast->map_x][raycast->map_y];
  if (raycast->side == 0)
    wallX = info->pos_y + raycast->perp_wall_dist * raycast->ray_dir_y;
  else
    wallX = info->pos_x + raycast->perp_wall_dist * raycast->ray_dir_x;
  wallX -= floor(wallX);
  texX = (int)(wallX * (double)TEX_WIDTH);
  if (raycast->side == 0 && raycast->ray_dir_x > 0)
    texX = TEX_WIDTH - texX - 1;
  if (raycast->side == 1 && raycast->ray_dir_y < 0)
    texX = TEX_WIDTH - texX - 1;
  coordinate_texture(info, raycast, x, texNum, texX);
}