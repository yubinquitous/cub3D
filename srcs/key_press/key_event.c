/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:38 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 13:55:03 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
		exit(0);
	mlx_clear_window(info->game.mlx, info->game.win);
	main_loop(info);
	return (0);
}
