/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:15 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 14:50:01 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../mlx/mlx.h"
# include "cub3d.h"
# include <math.h>
# include <stdlib.h>

# define K_A 0
# define K_W 13
# define K_S 1
# define K_D 2
# define K_ESC 53
# define K_AR_L 123
# define K_AR_R 124

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
}	t_raycast;

int		main_loop(t_info *info);
void	load_texture(t_info *info);
int		exit_game(t_info *info);

/* calc */
void	update_raycast(t_info *info, t_raycast *raycast, int x);
void	execute_dda(t_info *info, t_raycast *raycast);
void	calc_texture(t_info *info, t_raycast *raycast, int x);
void	detect_wall(t_info *info, t_raycast *raycast);
void	distance_to_wall(t_info *info, t_raycast *raycast);

/* key_press */
int		key_press(int key, t_info *info);
void	move_forward(t_info *info);
void	move_backward(t_info *info);
void	move_left(t_info *info);
void	move_right(t_info *info);
void	look_left(t_info *info);
void	look_right(t_info *info);

#endif
