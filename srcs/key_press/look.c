/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:42 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 13:57:20 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	look_right(t_info *info)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &(info->player);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(info->rot_speed)
		- player->dir_y * sin(info->rot_speed);
	player->dir_y = old_dir_x * sin(info->rot_speed)
		+ player->dir_y * cos(info->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(info->rot_speed)
		- player->plane_y * sin(info->rot_speed);
	player->plane_y = old_plane_x * sin(info->rot_speed)
		+ player->plane_y * cos(info->rot_speed);
}

void	look_left(t_info *info)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &(info->player);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-info->rot_speed)
		- player->dir_y * sin(-info->rot_speed);
	player->dir_y = old_dir_x * sin(-info->rot_speed)
		+ player->dir_y * cos(-info->rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-info->rot_speed)
		- player->plane_y * sin(-info->rot_speed);
	player->plane_y = old_plane_x * sin(-info->rot_speed)
		+ player->plane_y * cos(-info->rot_speed);
}
