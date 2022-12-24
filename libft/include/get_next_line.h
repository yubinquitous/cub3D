/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:54:05 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/02 00:45:15 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUF_SIZE
#  define BUF_SIZE 4096
# endif

typedef struct s_line
{
	char	*str;
	char	*old_str;
	size_t	old_len;
	size_t	new_len;
	ssize_t	read_cnt;
	int		lf;
}			t_line;

#endif
