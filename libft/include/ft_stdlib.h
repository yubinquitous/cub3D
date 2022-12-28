/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:29:46 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/28 16:56:52 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

int		ft_atoi(const char *nptr);
char	*ft_itoa(int value, char *buffer, int radix);

void	*safe_malloc(size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_free(void **ptr);

#endif
