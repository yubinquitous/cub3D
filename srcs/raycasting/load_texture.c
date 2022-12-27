/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:57:55 by yubin             #+#    #+#             */
/*   Updated: 2022/12/27 13:57:19 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

static void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img_ptr = mlx_xpm_file_to_image(info->game.mlx, path, &img->img_width, \
		&img->img_height);
	if (!img->img_ptr)
		exit(print_error("mlx_xpm_file_to_image() failed"));
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l, \
		&img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->game.mlx, img->img_ptr);
}

void	load_texture(t_info *info)
{
	t_img	img;

	ft_memset(info->game.texture, 0, sizeof(info->game.texture));
	load_image(info, info->game.texture[0], info->texture_path[0], &img);
	load_image(info, info->game.texture[1], info->texture_path[1], &img);
	load_image(info, info->game.texture[2], info->texture_path[2], &img);
	load_image(info, info->game.texture[3], info->texture_path[3], &img);
}
