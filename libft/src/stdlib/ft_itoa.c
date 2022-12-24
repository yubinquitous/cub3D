/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:18:29 by kijsong           #+#    #+#             */
/*   Updated: 2022/10/12 11:43:47 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_numlen(long long num, int radix)
{
	int	len;

	len = (num == 0);
	while (num)
	{
		len++;
		num /= radix;
	}
	return (len);
}

char	*ft_itoa(int value, char *buffer, int radix)
{
	const char	digits[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	long long	num;
	int			len;

	num = value;
	if (radix != 10 && num < 0)
		num = (unsigned)value;
	len = ft_numlen(num, radix);
	if (num < 0)
	{
		len++;
		num *= -1;
		buffer[0] = '-';
	}
	else if (num == 0)
		buffer[0] = '0';
	buffer[len] = '\0';
	while (num)
	{
		buffer[--len] = digits[num % radix];
		num /= radix;
	}
	return (buffer);
}
