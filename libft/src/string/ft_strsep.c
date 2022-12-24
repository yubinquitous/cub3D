/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:58:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:55:01 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*str;
	char	*end;

	str = *stringp;
	if (!str)
		return (NULL);
	end = str + ft_strcspn(str, delim);
	if (*end)
		*end++ = '\0';
	else
		end = NULL;
	*stringp = end;
	return (str);
}
