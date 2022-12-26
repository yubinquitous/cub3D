#include "raycasting.h"

void move_forward(t_info *info) {
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

// void	move_left(t_info *info)
// {
// 	t_player *player;

// 	player = &(info->player);
	
// }