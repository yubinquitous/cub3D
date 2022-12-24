/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/12/24 13:51:30 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "cub3d.h"

static void	init_info(t_info *info)
{
	ft_memset(info->floor, -1, sizeof(info->floor) / sizeof(int));
	ft_memset(info->ceilling, -1, sizeof(info->ceilling) / sizeof(int));
	ft_memset(info->resolution, -1, sizeof(info->resolution) / sizeof(int));
	ft_memset(info->texture, NULL, sizeof(info->texture) / sizeof(char *));
	info->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	init_info(&info);
	parse_file(&info, argv[1]);
	return (0);
}
