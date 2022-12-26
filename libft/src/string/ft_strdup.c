/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:14:15 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:54:14 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/ft_string.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = malloc(size);
	if (!dup)
		return (NULL);
	return (ft_memcpy(dup, s, size));
}
