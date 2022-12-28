/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:34:06 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/19 13:10:18 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	len;
	char	table[256];

	ft_memset(table, 0, sizeof(table));
	while (*set)
		table[*(const unsigned char *)set++] = 1;
	while (*s && table[*(const unsigned char *)s])
		s++;
	len = ft_strlen(s);
	while (len && table[(const unsigned char)s[len - 1]])
		len--;
	return (ft_substr(s, 0, len));
}
