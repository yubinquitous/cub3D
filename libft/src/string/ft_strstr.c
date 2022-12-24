/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:40:36 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:50:16 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
