/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:17:22 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/14 09:34:31 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;

	d_len = ft_strlen(dest);
	if (size <= d_len)
		return (size + ft_strlen(src));
	return (d_len + ft_strlcpy(dest + d_len, src, size - d_len));
}
