/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:42 by yubin             #+#    #+#             */
/*   Updated: 2022/12/26 21:57:42 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void look_right(t_info *info)
{
	t_player *player;
	double	oldDirX;
	double	oldPlaneX;

	player = &(info->player);
	oldDirX = player->dir_x;
	player->dir_x =
		player->dir_x * cos(info->rot_speed) - player->dir_y * sin(info->rot_speed);
	player->dir_y =
		oldDirX * sin(info->rot_speed) + player->dir_y * cos(info->rot_speed);
	oldPlaneX = player->plane_x;
	player->plane_x = player->plane_x * cos(info->rot_speed) -
					player->plane_y * sin(info->rot_speed);
	player->plane_y =
		oldPlaneX * sin(info->rot_speed) + player->plane_y * cos(info->rot_speed);
}

void look_left(t_info *info)
{
	t_player *player;
	double oldDirX;
	double oldPlaneX;

	player = &(info->player);
	oldDirX = player->dir_x;
	player->dir_x =
		player->dir_x * cos(-info->rot_speed) - player->dir_y * sin(-info->rot_speed);
	player->dir_y =
		oldDirX * sin(-info->rot_speed) + player->dir_y * cos(-info->rot_speed);
	oldPlaneX = player->plane_x;
	player->plane_x = player->plane_x * cos(-info->rot_speed) -
					player->plane_y * sin(-info->rot_speed);
	player->plane_y =
		oldPlaneX * sin(-info->rot_speed) + player->plane_y * cos(-info->rot_speed);
}