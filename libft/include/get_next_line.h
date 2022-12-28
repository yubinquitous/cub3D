/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:54:05 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/25 22:13:45 by son-yeong-w      ###   ########.fr       */
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
