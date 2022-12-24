/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:19:14 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/20 03:01:10 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "../../include/ft_string.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	rem;
	size_t	len;
	ssize_t	cnt;

	rem = ft_strlen(s);
	while (rem)
	{
		len = rem;
		if (len > SSIZE_MAX)
			len = SSIZE_MAX;
		cnt = write(fd, s, len);
		if (cnt < 0)
			return (-1);
		s += cnt;
		rem -= cnt;
	}
	return (0);
}
