/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:31 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 13:54:42 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	detect_wall(t_info *info, t_raycast *raycast)
{
	while (1)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (info->map[raycast->map_x][raycast->map_y] == '1')
			break ;
	}
}

void	distance_to_wall(t_info *info, t_raycast *raycast)
{
	if (raycast->side == 0)
		raycast->perp_wall_dist = (raycast->map_x - info->player.pos_x \
		+ (1 - raycast->step_x) / 2.) / raycast->ray_dir_x;
	else
		raycast->perp_wall_dist = (raycast->map_y - info->player.pos_y \
		+ (1 - raycast->step_y) / 2.) / raycast->ray_dir_y;
	raycast->line_height = (int)(WINDOW_HEIGHT / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + WINDOW_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + WINDOW_HEIGHT / 2;
	if (raycast->draw_end >= WINDOW_HEIGHT)
		raycast->draw_end = WINDOW_HEIGHT - 1;
}
