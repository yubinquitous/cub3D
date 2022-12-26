#include "../../includes/raycasting.h"

static void load_image(t_info *info, int *texture, char *path, t_img *img) {
  int x;
  int y;

  img->img =
      mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
  img->data =
      (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
  x = -1;
  y = -1;
  while (++y < img->img_height) {
    while (++x < img->img_width)
      texture[img->img_width * y + x] = img->data[img->img_width * y + x];
  }
  mlx_destroy_image(info->mlx, img->img);
}

void load_texture(t_info *info) {
  t_img img;

  // TODO: 파싱 후 텍스쳐 변경
  load_image(info, info->texture[0], "textures/eagle.xpm", &img);
  load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
  load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
  load_image(info, info->texture[3], "textures/greystone.xpm", &img);
}