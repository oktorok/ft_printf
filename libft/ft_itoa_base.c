/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:18:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/20 20:54:12 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calcdigits(int val, int bas)
{
	int dig;

	dig = 1;
	while (val / bas)
	{
		val = val / bas;
		dig++;
	}
	return (dig);
}

static void		calcnum(char *res, int value, int base)
{
	if (value < base)
		res[*i] = value;
	else
		res[*i] = value % base;
	if (res[*i] >= 10)
		res[*i] += -10 + 'A';
	else
		res[*i] += '0';
	value = value / base;
	digits--;
}

char			*ft_itoa_base(int value, int base)
{
	int		digits;
	int		neg;
	char	*res;

	if (base < 2 || base > 16)
		return (NULL);
	neg = 0;
	if (value < 0)
	{
		if (value == -2147483648)
			return ("-2147483648");
		value = -value;
		if (base == 10)
			neg = 1;
	}
	digits = calcdigits(value, base);
	if (!(res = (char *)malloc(sizeof(char) * (neg + digits))))
		return (NULL);
	res += digits + neg - 1;
	if (neg)
		res[0] = '-';
	while (digits--)
		calcnum(res--, value, base);
	return (res);
}
