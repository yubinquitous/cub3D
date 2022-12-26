/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:12:30 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:38:26 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ctype.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	sign;

	n = 0;
	while (ft_isspace(*nptr))
		nptr++;
	sign = (*nptr == '-') - (*nptr == '+');
	if (sign)
		nptr++;
	else
		sign = -1;
	while (ft_isdigit(*nptr))
		n = n * 10 - (*nptr++ - '0');
	return (n * sign);
}
