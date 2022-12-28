/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:26 by yubin             #+#    #+#             */
/*   Updated: 2022/12/28 17:05:09 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	draw_ceiling(t_info *info, t_raycast *raycast, int x)
{
	int	y;

	y = -1;
	while (++y < raycast->draw_start)
	{
		info->game.buf[y][x] = 0x00000000;
		info->game.buf[y][x] += info->ceiling[0] << 16;
		info->game.buf[y][x] += info->ceiling[1] << 8;
		info->game.buf[y][x] += info->ceiling[2];
	}
}

static void	draw_floor(t_info *info, t_raycast *raycast, int x)
{
	int	y;

	y = raycast->draw_end - 1;
	while (++y < WINDOW_HEIGHT)
	{
		info->game.buf[y][x] = 0x00000000;
		info->game.buf[y][x] += info->floor[0] << 16;
		info->game.buf[y][x] += info->floor[1] << 8;
		info->game.buf[y][x] += info->floor[2];
	}
}

static void	coordinate_texture(t_info *info, t_raycast *raycast,
							int x, int tex_x)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		y;
	int		color;

	step = 1.0 * TEX_HEIGHT / raycast->line_height;
	tex_pos = (raycast->draw_start - WINDOW_HEIGHT / 2.
			+ raycast->line_height / 2.) * step;
	draw_ceiling(info, raycast, x);
	draw_floor(info, raycast, x);
	y = raycast->draw_start - 1;
	while (++y < raycast->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color
			= info->game.texture[raycast->tex_num][TEX_HEIGHT * tex_y + tex_x];
		info->game.buf[y][x] = color;
	}
}

static void	set_tex_num(t_raycast *raycast)
{
	if (raycast->side == 0)
	{
		if (raycast->ray_dir_x > 0)
			raycast->tex_num = SO;
		else
			raycast->tex_num = NO;
	}
	else
	{
		if (raycast->ray_dir_y > 0)
			raycast->tex_num = EA;
		else
			raycast->tex_num = WE;
	}
}

void	calc_texture(t_info *info, t_raycast *raycast, int x)
{
	double	wall_x;
	int		tex_x;

	set_tex_num(raycast);
	if (raycast->side == 0)
		wall_x = info->player.pos_y
			+ raycast->perp_wall_dist * raycast->ray_dir_y;
	else
		wall_x = info->player.pos_x
			+ raycast->perp_wall_dist * raycast->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)((1 - wall_x) * (double)TEX_WIDTH);
	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	coordinate_texture(info, raycast, x, tex_x);
}
