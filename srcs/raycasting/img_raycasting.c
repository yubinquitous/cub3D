#include "../includes/raycasting.h"

void draw(t_info *info) {
  int x;
  int y;

  x = -1;
  y = -1;
  while (++y < WINDOW_HEIGHT) {
    while (++x < WINDOW_WIDTH)
      info->img.data[y * WINDOW_WIDTH + x] = info->buf[y][x];
  }
  mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void calc(t_info *info) {
  int x;
  t_raycast raycast;

  memset(info->buf, 0, sizeof(info->buf));
  memset(&raycast, 0, sizeof(t_raycast));
  x = -1;
  while (++x < WINDOW_WIDTH) {
    update_raycast(info, &raycast, x);
    execute_dda(info, &raycast);
    detect_wall(info, &raycast);
    distance_to_wall(info, &raycast);
    calc_texture(info, &raycast, x);
  }
}

int main_loop(t_info *info) {
  calc(info);
  draw(info);
  return (0);
}

int main(void) {
  t_info info;

  memset(&info, 0, sizeof(info));
  info.mlx = mlx_init();

  // info.pos_x = 22.0;
  // info.pos_y = 11.5;
  // info.dir_x = -1.0;
  // info.dir_y = 0.0;
  // info.plane_x = 0.0;
  // info.plane_y = 0.66;

  load_texture(&info);

  // info.move_speed = 0.05;
  // info.rot_speed = 0.05;
  info.win = mlx_new_window(info.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
  info.img.img = mlx_new_image(info.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
  info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
                                           &info.img.size_l, &info.img.endian);

  mlx_loop_hook(info.mlx, &main_loop, &info);
  mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
  mlx_loop(info.mlx);
}
