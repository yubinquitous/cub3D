/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:26 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 14:02:41 by yubin            ###   ########.fr       */
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
		if (raycast->side == 1)
			color = (color >> 1) & 8355711;
		info->game.buf[y][x] = color;
	}
}

void	calc_texture(t_info *info, t_raycast *raycast, int x)
{
	double	wall_x;
	int		tex_x;

	raycast->tex_num = info->map[raycast->map_x][raycast->map_y] - '0' - 1;
	if (raycast->side == 0)
		wall_x = info->player.pos_y
			+ raycast->perp_wall_dist * raycast->ray_dir_y;
	else
		wall_x = info->player.pos_x
			+ raycast->perp_wall_dist * raycast->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (raycast->side == 0 && raycast->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (raycast->side == 1 && raycast->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	coordinate_texture(info, raycast, x, tex_x);
}
