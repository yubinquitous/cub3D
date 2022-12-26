/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:29:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:43:00 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int value, char *buffer, int radix);

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_free(void **ptr);

void	*ft_bsearch(const void *key, const void *base, size_t nmemb, size_t size);

#endif
