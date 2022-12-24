#include "../includes/raycasting.h"
#include <string.h> // TODO: ft_memset으로 변경

void draw(t_info *info) {
  int x;
  int y;

  x = -1;
  y = -1;
  while (++y < height) {
    while (++x < width)
      info->img.data[y * width + x] = info->buf[y][x];
  }
  mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void update_raycast(t_info *info, t_raycast *raycast, int x) {
  raycast->cameraX = 2 * x / (double)width - 1;
  raycast->rayDirX = info->dirX + info->planeX * raycast->cameraX;
  raycast->rayDirY = info->dirY + info->planeY * raycast->cameraX;
  raycast->mapX = (int)info->posX;
  raycast->mapY = (int)info->posY;
  raycast->deltaDistX = fabs(1 / raycast->rayDirX);
  raycast->deltaDistY = fabs(1 / raycast->rayDirY);
}

void execute_dda(t_info *info, t_raycast *raycast) {
  if (raycast->rayDirX < 0) {
    raycast->stepX = -1;
    raycast->sideDistX = (info->posX - raycast->mapX) * raycast->deltaDistX;
  } else {
    raycast->stepX = 1;
    raycast->sideDistX =
        (raycast->mapX + 1.0 - info->posX) * raycast->deltaDistX;
  }
  if (raycast->rayDirY < 0) {
    raycast->stepY = -1;
    raycast->sideDistY = (info->posY - raycast->mapY) * raycast->deltaDistY;
  } else {
    raycast->stepY = 1;
    raycast->sideDistY =
        (raycast->mapY + 1.0 - info->posY) * raycast->deltaDistY;
  }
}

void detect_wall(t_info *info, t_raycast *raycast) {
  while (1) {
    // jump to next map square, OR in x-direction, OR in y-direction
    if (raycast->sideDistX < raycast->sideDistY) {
      raycast->sideDistX += raycast->deltaDistX;
      raycast->mapX += raycast->stepX;
      raycast->side = 0;
    } else {
      raycast->sideDistY += raycast->deltaDistY;
      raycast->mapY += raycast->stepY;
      raycast->side = 1;
    }
    // Check if ray has hit a wall
    if (info->worldMap[raycast->mapX][raycast->mapY] > 0)
      break;
  }
}

void distance_to_wall(t_info *info, t_raycast *raycast) {
  if (raycast->side == 0)
    raycast->perpWallDist =
        (raycast->mapX - info->posX + (1 - raycast->stepX) / 2.) /
        raycast->rayDirX;
  else
    raycast->perpWallDist =
        (raycast->mapY - info->posY + (1 - raycast->stepY) / 2.) /
        raycast->rayDirY;

  // Calculate height of line to draw on screen
  raycast->lineHeight = (int)(height / raycast->perpWallDist);
  // calculate lowest and highest pixel to fill in current stripe
  raycast->drawStart = -raycast->lineHeight / 2 + height / 2;
  if (raycast->drawStart < 0)
    raycast->drawStart = 0;
  raycast->drawEnd = raycast->lineHeight / 2 + height / 2;
  if (raycast->drawEnd >= height)
    raycast->drawEnd = height - 1;
}

void coordinate_texture(t_info *info, t_raycast *raycast, int x, int texNum,
                        int texX) {
  double step;
  double texPos;
  int texY;
  int i;

  // How much to increase the texture coordinate perscreen pixel
  step = 1.0 * texHeight / raycast->lineHeight;
  // Starting texture coordinate
  texPos = (raycast->drawStart - height / 2. + raycast->lineHeight / 2.) * step;
  i = raycast->drawStart;
  while (i < raycast->drawEnd) {
    texY = (int)texPos & (texHeight - 1);
    texPos += step;
    int color = info->texture[texNum][texHeight * texY + texX];
    if (raycast->side == 1)
      color = (color >> 1) & 8355711;
    info->buf[i][x] = color;
    i++;
  }
}

void draw_texture(t_info *info, t_raycast *raycast, int x) {
  int texNum;   // texturing calculations
  double wallX; // calculate value of wallX
  int texX;

  texNum = info->worldMap[raycast->mapX][raycast->mapY];
  if (raycast->side == 0)
    wallX = info->posY + raycast->perpWallDist * raycast->rayDirY;
  else
    wallX = info->posX + raycast->perpWallDist * raycast->rayDirX;
  wallX -= floor(wallX);
  // x coordinate on the texture
  texX = (int)(wallX * (double)texWidth);
  if (raycast->side == 0 && raycast->rayDirX > 0)
    texX = texWidth - texX - 1;
  if (raycast->side == 1 && raycast->rayDirY < 0)
    texX = texWidth - texX - 1;
  coordinate_texture(info, raycast, x, texNum, texX);
}

void calc(t_info *info) {
  int x;
  t_raycast raycast;

  memset(info->buf, 0, sizeof(info->buf));
  memset(&raycast, 0, sizeof(t_raycast));
  x = 0;
  while (x < width) {
    update_raycast(info, &raycast, x);
    execute_dda(info, &raycast);
    detect_wall(info, &raycast);
    distance_to_wall(info, &raycast);
    draw_texture(info, &raycast, x);
    x++;
  }
}

int main_loop(t_info *info) {
  calc(info);
  draw(info);
  return (0);
}

void load_image(t_info *info, int *texture, char *path, t_img *img) {
  img->img =
      mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
  img->data =
      (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
  for (int y = 0; y < img->img_height; y++) {
    for (int x = 0; x < img->img_width; x++) {
      texture[img->img_width * y + x] = img->data[img->img_width * y + x];
    }
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

int main(void) {
  t_info info;
  info.mlx = mlx_init();

  info.posX = 22.0;
  info.posY = 11.5;
  info.dirX = -1.0;
  info.dirY = 0.0;
  info.planeX = 0.0;
  info.planeY = 0.66;

  memset(info.buf, 0, sizeof(info.buf));

  // if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
  //   return (-1);
  // for (int i = 0; i < 8; i++) {
  //   if (!(info.texture[i] =
  //             (int *)malloc(sizeof(int) * (texHeight * texWidth))))
  //     return (-1);
  // }
  memset(info.texture, 0, sizeof(info.texture));
  load_texture(&info);

  info.moveSpeed = 0.05;
  info.rotSpeed = 0.05;

  info.win = mlx_new_window(info.mlx, width, height, "mlx");

  info.img.img = mlx_new_image(info.mlx, width, height);
  info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
                                           &info.img.size_l, &info.img.endian);

  mlx_loop_hook(info.mlx, &main_loop, &info);
  mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

  mlx_loop(info.mlx);
}
