/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:32:31 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:41:03 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_compar(const void *p1, const void *p2)
{
	return (*(const int *)p1 - *(const int *)p2);
}

void	*ft_bsearch(const void *key, const void *base, size_t nmemb, size_t size)
{
	const void	*mid;
	int			sign;

	while (nmemb)
	{
		mid = (const char *)base + (nmemb / 2) * size;
		sign = ft_compar(key, mid);
		if (sign < 0)
			nmemb /= 2;
		else if (sign > 0)
		{
			base = (const char *)mid + size;
			nmemb -= nmemb / 2 + 1;
		}
		else
			return ((void *)mid);
	}
	return (NULL);
}
