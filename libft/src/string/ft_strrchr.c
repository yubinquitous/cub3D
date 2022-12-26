/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:23:25 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/11 00:58:14 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	c = (unsigned char)c;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (p[i] == c)
			return ((char *)(p + i));
	}
	return (NULL);
}
