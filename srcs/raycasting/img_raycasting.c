#include "raycasting.h"

void draw(t_info *info) {
  t_game game;
  int x;
  int y;

  game = info->game;
  x = -1;
  y = -1;
  while (++y < WINDOW_HEIGHT) {
    while (++x < WINDOW_WIDTH)
      game.img.data[y * WINDOW_WIDTH + x] = game.buf[y][x];
  }
  mlx_put_image_to_window(game.mlx, game.win, game.img.img_ptr, 0, 0);
}

void calc(t_info *info) {
  int x;
  t_raycast raycast;

  ft_memset(info->game.buf, 0, sizeof(info->game.buf));
  ft_memset(&raycast, 0, sizeof(t_raycast));
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
  t_game game;

  game = info.game;
  ft_memset(&info, 0, sizeof(info));
  game.mlx = mlx_init();
  // player.dir_x = -1.0;
  // player.dir_y = 0.0;
  // player.plane_x = 0.0;
  // player.plane_y = 0.66;

  load_texture(&info);
  info.move_speed = 0.05;
  info.rot_speed = 0.05;
  game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
  game.img.img_ptr = mlx_new_image(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
  game.img.data = mlx_get_data_addr(game.img.img_ptr, &game.img.bpp,
                                           &game.img.size_l, &game.img.endian);

  mlx_loop_hook(game.mlx, &main_loop, &info);
  mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
  mlx_loop(game.mlx);
}
