/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:53:47 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:47:25 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*p;
	char		table[256];

	ft_memset(table, 0, sizeof(table));
	while (*accept)
		table[*(const unsigned char *)accept++] = 1;
	p = s;
	while (*p && table[*(const unsigned char *)p])
		p++;
	return (p - s);
}
