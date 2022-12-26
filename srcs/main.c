/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:34:38 by yoson             #+#    #+#             */
/*   Updated: 2022/12/26 13:58:17 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	
	return (0);
}
