/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:28:29 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 14:45:10 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw(t_info *info)
{
	t_game	*game;
	int		x;
	int		y;

	game = &(info->game);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		game->img.data[y * WINDOW_WIDTH + x] = game->buf[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}

void	calc(t_info *info)
{
	int			x;
	t_raycast	raycast;

	ft_memset(info->game.buf, 0, sizeof(info->game.buf));
	ft_memset(&raycast, 0, sizeof(t_raycast));
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		update_raycast(info, &raycast, x);
		execute_dda(info, &raycast);
		detect_wall(info, &raycast);
		distance_to_wall(info, &raycast);
		calc_texture(info, &raycast, x);
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

void	init_plane(t_player *player)
{
	player->plane_x = player->dir_y * -1 * 0.66;
	player->plane_y = player->dir_x * 0.66;
}

void	raycasting(t_info *info)
{
	t_game	*game;

	game = &(info->game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(print_error("mlx_init() failed"));
	init_plane(&(info->player));
	load_texture(info);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
	if (!game->win)
		exit(print_error("mlx_new_window() failed"));
	game->img.img_ptr = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->img.img_ptr)
		exit(print_error("mlx_new_image() failed"));
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, \
	&game->img.bpp, &game->img.size_l, &game->img.endian);
	mlx_loop_hook(game->mlx, main_loop, info);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, key_press, info);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, exit_game, info);
	mlx_loop(game->mlx);
}
