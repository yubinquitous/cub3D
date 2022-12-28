/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:13 by yubin             #+#    #+#             */
/*   Updated: 2022/12/28 14:04:38 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	update_raycast(t_info *info, t_raycast *raycast, int x)
{
	raycast->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	raycast->ray_dir_x = info->player.dir_x
		+ info->player.plane_x * raycast->camera_x;
	raycast->ray_dir_y = info->player.dir_y
		+ info->player.plane_y * raycast->camera_x;
	raycast->map_x = (int)info->player.pos_x;
	raycast->map_y = (int)info->player.pos_y;
	if (raycast->ray_dir_y == 0)
		raycast->delta_dist_x = 0;
	else if (raycast->ray_dir_x == 0)
		raycast->delta_dist_x = 1;
	else
		raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	if (raycast->ray_dir_x == 0)
		raycast->delta_dist_y = 0;
	else if (raycast->ray_dir_y == 0)
		raycast->delta_dist_y = 1;
	else
		raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
}

void	execute_dda(t_info *info, t_raycast *raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = \
			(info->player.pos_x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = \
			(raycast->map_x + 1.0 - info->player.pos_x) * raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = \
			(info->player.pos_y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = \
			(raycast->map_y + 1.0 - info->player.pos_y) * raycast->delta_dist_y;
	}
}
