/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:38 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 14:49:12 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	exit_game(t_info *info)
{
	mlx_destroy_image(info->game.mlx, info->game.win);
	exit(EXIT_SUCCESS);
}

int	key_press(int key, t_info *info)
{
	if (key == K_W)
		move_forward(info);
	else if (key == K_S)
		move_backward(info);
	else if (key == K_D)
		move_right(info);
	else if (key == K_A)
		move_left(info);
	else if (key == K_AR_L)
		look_left(info);
	else if (key == K_AR_R)
		look_right(info);
	else if (key == K_ESC)
		exit_game(info);
	mlx_clear_window(info->game.mlx, info->game.win);
	main_loop(info);
	return (0);
}
