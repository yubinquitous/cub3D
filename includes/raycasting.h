#include "key_macos.h"
#include "../mlx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480
#define texSize 4096
#define texCount 4

typedef struct s_img {
  void *img;
  int *data;

  int size_l;
  int bpp;
  int endian;
  int img_width;
  int img_height;
} t_img;

typedef struct s_info {
  double posX;
  double posY;
  double dirX;
  double dirY;
  double planeX;
  double planeY;
  void *mlx;
  void *win;
  t_img img;
  int buf[height][width];
  int texture[texCount][texSize];
  int worldMap[mapWidth][mapHeight];
  double moveSpeed;
  double rotSpeed;
} t_info;

typedef struct s_raycast {
  double  cameraX;
  double  rayDirX;
  double  rayDirY;
  int     mapX;
  int     mapY;
  double  sideDistX;
  double  sideDistY;
  double  deltaDistX;
  double  deltaDistY;
  double  perpWallDist;
  int     stepX;
  int     stepY;
  int     side;
  int     lineHeight;
  int     drawStart;
  int     drawEnd;
} t_raycast;

int main_loop(t_info *info);
int key_press(int key, t_info *info);
