/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:30:45 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/19 13:00:51 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_list.h"
#include "../../include/ft_stdlib.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	ft_free((void *)&lst);
}
