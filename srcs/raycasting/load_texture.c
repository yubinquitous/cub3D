#include "raycasting.h"

static void load_image(t_info *info, int *texture, char *path, t_img *img) {
  int x;
  int y;

  img->img_ptr =
      mlx_xpm_file_to_image(info->game.mlx, path, &img->img_width, &img->img_height);
  img->data =
      mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, &img->endian);
  x = -1;
  y = -1;
  while (++y < img->img_height) {
    while (++x < img->img_width)
      texture[img->img_width * y + x] = img->data[img->img_width * y + x];
  }
  mlx_destroy_image(info->game.mlx, img->img_ptr);
}

void load_texture(t_info *info) {
  t_img img;

  // TODO: 파싱 후 텍스쳐 변경
  load_image(info, info->game.texture[0], "textures/eagle.xpm", &img);
  load_image(info, info->game.texture[1], "textures/redbrick.xpm", &img);
  load_image(info, info->game.texture[2], "textures/purplestone.xpm", &img);
  load_image(info, info->game.texture[3], "textures/greystone.xpm", &img);
}
