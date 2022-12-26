/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:20:50 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/11 00:58:56 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	c = (unsigned char)c;
	while (*p && *p != c)
		p++;
	if (*p != c)
		return (NULL);
	return ((char *)p);
}
