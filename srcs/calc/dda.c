#include "../../includes/raycasting.h"
#include <stdio.h> //test

void update_raycast(t_info *info, t_raycast *raycast, int x) {
  raycast->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
  raycast->ray_dir_x = info->player.dir_x + info->player.plane_x * raycast->camera_x;
  raycast->ray_dir_y = info->player.dir_y + info->player.plane_y * raycast->camera_x;
  // printf("plane_x: %f, plane_y: %f, x: %d\n", info->player.plane_x, info->player.plane_y, x);
  // printf("ray_dir_x: %f, ray_dir_y: %f\ncameraX: %f\n", raycast->ray_dir_x, raycast->ray_dir_y, raycast->camera_x);
  raycast->map_x = (int)info->player.pos_x;
  raycast->map_y = (int)info->player.pos_y;
  // TODO : ray_dir_x, ray_dir_y 0 예외처리
  raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
  raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
}

void execute_dda(t_info *info, t_raycast *raycast) {
  if (raycast->ray_dir_x < 0) {
    raycast->step_x = -1;
    raycast->side_dist_x =
        (info->player.pos_x - raycast->map_x) * raycast->delta_dist_x;
  } else {
    raycast->step_x = 1;
    raycast->side_dist_x =
        (raycast->map_x + 1.0 - info->player.pos_x) * raycast->delta_dist_x;
  }
  if (raycast->ray_dir_y < 0) {
    raycast->step_y = -1;
    raycast->side_dist_y =
        (info->player.pos_y - raycast->map_y) * raycast->delta_dist_y;
  } else {
    raycast->step_y = 1;
    raycast->side_dist_y =
        (raycast->map_y + 1.0 - info->player.pos_y) * raycast->delta_dist_y;
  }
}
