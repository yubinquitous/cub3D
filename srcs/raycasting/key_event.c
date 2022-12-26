#include "raycasting.h"

static void move_forward(t_info *info) {
  t_player *player;

  player = &(info->player);
  if (!info->map[(int)(player->pos_x + player->dir_x * info->move_speed)]
                     [(int)(player->pos_y)])
    player->pos_x += player->dir_x * info->move_speed;
  if (!info->map[(int)(player->pos_x)]
                     [(int)(player->pos_y + player->dir_y * info->move_speed)])
    player->pos_y += player->dir_y * info->move_speed;
}

void move_backward(t_info *info) {
  t_player *player;

  player = &(info->player);
  if (!info->map[(int)(player->pos_x - player->dir_x * info->move_speed)]
                     [(int)(player->pos_y)])
    player->pos_x -= player->dir_x * info->move_speed;
  if (!info->map[(int)(player->pos_x)]
                     [(int)(player->pos_y - player->dir_y * info->move_speed)])
    player->pos_y -= player->dir_y * info->move_speed;
}

void move_right(t_info *info) {
  t_player *player;
  double oldDirX;
  double oldPlaneX;

  player = &(info->player);
  oldDirX = player->dir_x;
  player->dir_x =
      player->dir_x * cos(-info->rot_speed) - player->dir_y * sin(-info->rot_speed);
  player->dir_y =
      oldDirX * sin(-info->rot_speed) + player->dir_y * cos(-info->rot_speed);
  oldPlaneX = player->plane_x;
  player->plane_x = player->plane_x * cos(-info->rot_speed) -
                  player->plane_y * sin(-info->rot_speed);
  player->plane_y =
      oldPlaneX * sin(-info->rot_speed) + player->plane_y * cos(-info->rot_speed);
}

static void move_left(t_info *info) {
  t_player *player;
  double oldDirX;
  double oldPlaneX;

  player = &(info->player);
  oldDirX = player->dir_x;
  player->dir_x =
      player->dir_x * cos(info->rot_speed) - player->dir_y * sin(info->rot_speed);
  player->dir_y =
      oldDirX * sin(info->rot_speed) + player->dir_y * cos(info->rot_speed);
  oldPlaneX = player->plane_x;
  player->plane_x = player->plane_x * cos(info->rot_speed) -
                  player->plane_y * sin(info->rot_speed);
  player->plane_y =
      oldPlaneX * sin(info->rot_speed) + player->plane_y * cos(info->rot_speed);
}

int key_press(int key, t_info *info) {
  if (key == K_W)
    move_forward(info);
  else if (key == K_S)
    move_backward(info);
  else if (key == K_D)
    move_right(info);
  else if (key == K_A)
    move_left(info);
  else if (key == K_ESC)
    exit(0);
  mlx_clear_window(info->game.mlx, info->game.win);
  main_loop(info);
  return (0);
}
