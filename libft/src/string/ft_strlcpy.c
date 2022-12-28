/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:17:02 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/14 09:34:23 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*d;

	d = dest;
	if (size--)
	{
		while (size-- && *src)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (dest - d + ft_strlen(src));
}
