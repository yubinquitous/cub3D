/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:30:30 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/20 02:56:59 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
