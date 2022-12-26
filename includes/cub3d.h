/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:05:57 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 21:07:09 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ERROR -1

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480
# define TEX_SIZE 4096
# define TEX_COUNT 4

# include "enum.h"
# include "../libft/include/libft.h"

typedef struct s_img {
  void *img_ptr;
  int *data;
  int size_l;
  int bpp;
  int endian;
  int img_width;
  int img_height;
} t_img;

typedef struct s_player
{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
}	t_player;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img img;
	int buf[WINDOW_HEIGHT][WINDOW_WIDTH];
	int texture[TEX_COUNT][TEX_SIZE];
} 	t_game;

typedef struct s_info
{
	char	*texture_path[4];
	int		floor[3];
	int		ceiling[3];
	char	**map;
	t_player player;
	t_game game;
	double move_speed;
	double rot_speed;
}	t_info;

void	parse_file(t_info *info, char *filename);
void 	raycasting(t_info *info);

/* common_error */
int		print_error(char *error_msg);
int 	print_strerror(char *arg);

/* parser_utils */
char	*read_file(int fd);
int		is_valid_element(char *content);
int		is_cub_file(char *filename);
int 	is_map_content(char *line);
int		**get_visited(char **map);

/* parser_element_utils */
int		set_rgb(int dest[], char *content);
int		set_texture(char **dest, char *content);
int		has_all_element(t_info *info);

/* parser_map_utils */
int 	check_map_charset(int fd);
char    **get_map_array(int fd);
void 	set_player(t_info *info);

/* utils */
int 	find_strarr_len(char **str);
int 	is_only_digit(char *str);
int 	ft_allfree(void **ptr);
int		safe_open(char *filename);
void 	*safe_malloc(size_t size);

#endif
