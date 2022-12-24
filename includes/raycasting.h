#include "../mlx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <string.h> // TODO: ft_memset으로 변경

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define TEX_SIZE 4096
#define TEX_COUNT 4

# define K_A 0
# define K_W 13
# define K_S 1
# define K_D 2
# define K_ESC 53

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
  double pos_x;
  double pos_y;
  double dir_x;
  double dir_y;
  double plane_x;
  double plane_y;
  void *mlx;
  void *win;
  t_img img;
  int buf[WINDOW_HEIGHT][WINDOW_WIDTH];
  int texture[TEX_COUNT][TEX_SIZE];
  int worldMap[MAP_WIDTH][MAP_HEIGHT];  // TODO: parsing에서 동적할당 
  double move_speed;
  double rot_speed;
} t_info;

typedef struct s_raycast {
  double  camera_x;
  double  ray_dir_x;
  double  ray_dir_y;
  int     map_x;
  int     map_y;
  double  side_dist_x;
  double  side_dist_y;
  double  delta_dist_x;
  double  delta_dist_y;
  double  perp_wall_dist;
  int     step_x;
  int     step_y;
  int     side;
  int     line_height;
  int     draw_start;
  int     draw_end;
} t_raycast;

int main_loop(t_info *info);
int key_press(int key, t_info *info);

void load_texture(t_info *info);

// calc
void update_raycast(t_info *info, t_raycast *raycast, int x);
void execute_dda(t_info *info, t_raycast *raycast);
void calc_texture(t_info *info, t_raycast *raycast, int x);
void detect_wall(t_info *info, t_raycast *raycast);
void distance_to_wall(t_info *info, t_raycast *raycast);
