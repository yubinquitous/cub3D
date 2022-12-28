/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:12:30 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/26 21:33:51 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ctype.h"
#include "../../include/ft_string.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;

	while (*nptr == '0')
		nptr++;
	n = 0;
	i = -1;
	while (nptr[++i] && i < 4)
		n = n * 10 + nptr[i] - '0';
	return (n);
}
