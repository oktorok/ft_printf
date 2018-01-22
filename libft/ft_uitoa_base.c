/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:18:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 00:34:14 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calcdigits(unsigned int val, int bas)
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

static void		calcnum(char *res, unsigned int *value, int base)
{
	if (*value <(unsigned int)base)
		*res = *value;
	else
		*res = *value % base;
	if (*res >= 10)
		*res += -10 + 'A';
	else
		*res += '0';
	*value = *value / base;
}

char			*ft_uitoa_base(unsigned int value, int base)
{
	int		digits;
	char	*res;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	digits = calcdigits(value, base);
	if (!(res = (char *)malloc(sizeof(char) * (digits))))
		return (NULL);
	i = digits - 1;
	while (digits--)
		calcnum(&(res[i--]), &value, base);
	return (res);
}
