#include "raycasting.h"

void move_forward(t_info *info) {
  t_player *player;

  player = &(info->player);
  if (info->map[(int)(player->pos_x + player->dir_x * info->move_speed)]
                     [(int)(player->pos_y)] == '0')
    player->pos_x += player->dir_x * info->move_speed;
  if (info->map[(int)(player->pos_x)]
                     [(int)(player->pos_y + player->dir_y * info->move_speed)] == '0')
    player->pos_y += player->dir_y * info->move_speed;
}

void move_backward(t_info *info) {
  t_player *player;

  player = &(info->player);
  if (info->map[(int)(player->pos_x - player->dir_x * info->move_speed)]
                     [(int)(player->pos_y)] == '0')
    player->pos_x -= player->dir_x * info->move_speed;
  if (info->map[(int)(player->pos_x)]
                     [(int)(player->pos_y - player->dir_y * info->move_speed)] == '0')
    player->pos_y -= player->dir_y * info->move_speed;
}

void	move_left(t_info *info)
{
  t_player *player;
  double    move_speed;

  player = &(info->player);
  move_speed = info->move_speed * 3 / 2;
  if (info->map[(int)(player->pos_x - player->plane_x * move_speed)]
                     [(int)(player->pos_y)] == '0')
    player->pos_x -= player->plane_x * move_speed;
  if (info->map[(int)(player->pos_x)]
                     [(int)(player->pos_y - player->plane_y * move_speed)] == '0')
    player->pos_y -= player->plane_y * move_speed;
}

void	move_right(t_info *info)
{
  t_player *player;
  double    move_speed;

  player = &(info->player);
  move_speed = info->move_speed * 3 / 2;
  if (info->map[(int)(player->pos_x + player->plane_x * move_speed)]
                     [(int)(player->pos_y)] == '0')
    player->pos_x += player->plane_x * move_speed;
  if (info->map[(int)(player->pos_x)]
                     [(int)(player->pos_y + player->plane_y * move_speed)] == '0')
    player->pos_y += player->plane_y * move_speed;
}