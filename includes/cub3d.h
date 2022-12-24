/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:05:57 by yoson             #+#    #+#             */
/*   Updated: 2022/12/24 15:20:29 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ERROR		-1

# include "enum.h"

typedef struct s_info
{
	char	*texture[4];
	int		floor[3];
	int		ceilling[3];
	int		resolution[2];
	char	**map;
}	t_info;

void	parse_file(t_info *info, const char *filename);

#endif