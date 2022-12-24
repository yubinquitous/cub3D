/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/12/25 05:24:27 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* info print test*/
#include <stdio.h>
static void	test(t_info *info)
{
	int i;

	i = -1;
	while (++i < 4)
		printf("texture: %d: %s\n", i, info->texture[i]);
	i = -1;
	printf("floor: R:%d G:%d B:%d\n", info->floor[0], info->floor[1], info->floor[2]);
	printf("ceilling: R:%d G:%d B:%d\n", info->ceilling[0], info->ceilling[1], info->ceilling[2]);
	while (info->map[++i])
		printf("map content: %d: %s\n", i, info->map[i]);
}
/* info print test*/

static void	init_info(t_info *info)
{
	ft_memset(info->floor, -1, sizeof(info->floor));
	ft_memset(info->ceilling, -1, sizeof(info->ceilling));
	ft_memset(info->texture, 0, sizeof(info->texture));
	info->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 2)
		return (print_error("Invalid arguments"));
	init_info(&info);
	parse_file(&info, argv[1]);
	test(&info);
	return (0);
}
