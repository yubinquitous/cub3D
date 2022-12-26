/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/12/27 02:26:20 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_info(t_info *info)
{
	ft_memset(info->floor, -1, sizeof(info->floor));
	ft_memset(info->ceiling, -1, sizeof(info->ceiling));
	ft_memset(info->texture_path, 0, sizeof(info->texture_path));
	info->map = NULL;
	info->move_speed = 0.05;
  	info->rot_speed = 0.05;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2)
		return (print_error("Invalid arguments"));
	init_info(&info);
	parse_file(&info, argv[1]);
	raycasting(&info);
	return (0);
}
