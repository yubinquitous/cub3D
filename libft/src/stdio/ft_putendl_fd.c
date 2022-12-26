/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:19:24 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/19 14:22:15 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_stdio.h"

int	ft_putendl_fd(char *s, int fd)
{
	return (-(ft_putstr_fd(s, fd) < 0 || ft_putchar_fd('\n', fd) < 0));
}
