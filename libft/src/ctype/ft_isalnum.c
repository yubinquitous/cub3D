/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:24:37 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/23 09:30:10 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_ctype.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}