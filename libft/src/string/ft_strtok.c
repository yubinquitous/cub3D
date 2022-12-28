/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:57:05 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:56:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_string.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*p;

	if (!str)
		str = p;
	if (!str)
		return (NULL);
	str += ft_strspn(str, delim);
	if (!*str)
	{
		p = NULL;
		return (NULL);
	}
	p = str + ft_strcspn(str, delim);
	if (*p)
		*p++ = '\0';
	else
		p = NULL;
	return (str);
}
