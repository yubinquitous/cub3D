/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:42:57 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:47:46 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*p;
	char		table[256];

	ft_memset(table, 0, sizeof(table));
	while (*reject)
		table[*(const unsigned char *)reject++] = 1;
	p = s;
	while (*p && !table[*(const unsigned char *)p])
		p++;
	return (p - s);
}
