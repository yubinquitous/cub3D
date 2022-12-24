#include "../includes/raycasting.h"

static void move_forward(t_info *info) {
  if (!info->worldMap[(int)(info->posX + info->dirX * info->moveSpeed)]
                     [(int)(info->posY)])
    info->posX += info->dirX * info->moveSpeed;
  if (!info->worldMap[(int)(info->posX)]
                     [(int)(info->posY + info->dirY * info->moveSpeed)])
    info->posY += info->dirY * info->moveSpeed;
}

void move_backward(t_info *info) {
  if (!info->worldMap[(int)(info->posX - info->dirX * info->moveSpeed)]
                     [(int)(info->posY)])
    info->posX -= info->dirX * info->moveSpeed;
  if (!info->worldMap[(int)(info->posX)]
                     [(int)(info->posY - info->dirY * info->moveSpeed)])
    info->posY -= info->dirY * info->moveSpeed;
}

void move_right(t_info *info) {
  // both camera direction and camera plane must be rotated
  double oldDirX = info->dirX;
  info->dirX =
      info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
  info->dirY =
      oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
  double oldPlaneX = info->planeX;
  info->planeX =
      info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
  info->planeY =
      oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
}

static void move_left(t_info *info) {
  double oldDirX = info->dirX;
  info->dirX =
      info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
  info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
  double oldPlaneX = info->planeX;
  info->planeX =
      info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
  info->planeY =
      oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
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
