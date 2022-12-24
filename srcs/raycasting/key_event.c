#include "../includes/raycasting.h"

static void move_forward(t_info *info) {
  if (!info->worldMap[(int)(info->pos_x + info->dir_x * info->move_speed)]
                     [(int)(info->pos_y)])
    info->pos_x += info->dir_x * info->move_speed;
  if (!info->worldMap[(int)(info->pos_x)]
                     [(int)(info->pos_y + info->dir_y * info->move_speed)])
    info->pos_y += info->dir_y * info->move_speed;
}

void move_backward(t_info *info) {
  if (!info->worldMap[(int)(info->pos_x - info->dir_x * info->move_speed)]
                     [(int)(info->pos_y)])
    info->pos_x -= info->dir_x * info->move_speed;
  if (!info->worldMap[(int)(info->pos_x)]
                     [(int)(info->pos_y - info->dir_y * info->move_speed)])
    info->pos_y -= info->dir_y * info->move_speed;
}

void move_right(t_info *info) {
  // both camera direction and camera plane must be rotated
  double oldDirX = info->dir_x;
  info->dir_x =
      info->dir_x * cos(-info->rot_speed) - info->dir_y * sin(-info->rot_speed);
  info->dir_y =
      oldDirX * sin(-info->rot_speed) + info->dir_y * cos(-info->rot_speed);
  double oldPlaneX = info->plane_x;
  info->plane_x = info->plane_x * cos(-info->rot_speed) -
                  info->plane_y * sin(-info->rot_speed);
  info->plane_y =
      oldPlaneX * sin(-info->rot_speed) + info->plane_y * cos(-info->rot_speed);
}

static void move_left(t_info *info) {
  double oldDirX = info->dir_x;
  info->dir_x =
      info->dir_x * cos(info->rot_speed) - info->dir_y * sin(info->rot_speed);
  info->dir_y =
      oldDirX * sin(info->rot_speed) + info->dir_y * cos(info->rot_speed);
  double oldPlaneX = info->plane_x;
  info->plane_x = info->plane_x * cos(info->rot_speed) -
                  info->plane_y * sin(info->rot_speed);
  info->plane_y =
      oldPlaneX * sin(info->rot_speed) + info->plane_y * cos(info->rot_speed);
}

int key_press(int key, t_info *info) {
  if (key == K_W)
    move_forward(info);
  // move backwards if no wall behind you
  else if (key == K_S)
    move_backward(info);
  // rotate to the right
  else if (key == K_D)
    move_right(info);
  // rotate to the left
  else if (key == K_A)
    move_left(info);
  // both camera direction and camera plane must be rotated
  else if (key == K_ESC)
    exit(0);
  mlx_clear_window(info->mlx, info->win);
  main_loop(info);
  return (0);
}
