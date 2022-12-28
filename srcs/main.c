/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/12/28 16:43:48 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_info(t_info *info)
{
	ft_memset(info->floor, -1, sizeof(info->floor));
	ft_memset(info->ceiling, -1, sizeof(info->ceiling));
	ft_memset(info->texture_path, 0, sizeof(info->texture_path));
	info->map = NULL;
	info->move_speed = 0.2;
	info->rot_speed = 0.2;
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
