/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:05:57 by yoson             #+#    #+#             */
/*   Updated: 2022/12/25 05:22:12 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ERROR		-1

# include "enum.h"
# include "../libft/include/libft.h"

typedef struct s_info
{
	char	*texture[4];
	int		floor[3];
	int		ceilling[3];
	char	**map;
}	t_info;

void	parse_file(t_info *info, char *filename);

/* common_error */
int		print_error(char *error_msg);
int		print_perror(void);

/* parser_utils */
char	**read_file(char *filename);
int		is_valid_content(char *content);
int		is_cub_file(char *filename);
int 	is_map_content(char *line);

/* parser_element_utils*/
int		validate_rgb(char *rgb);
int		set_rgb(int dest[], char *content);
int		set_texture(char **dest, char *content);
int		has_all_element(t_info *info);

/* utils */
int 	find_strarr_len(char **str);
int 	is_only_digit(char *str);
int 	ft_allfree(char **str);

#endif
