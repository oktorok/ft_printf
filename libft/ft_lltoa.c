/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:38:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 18:33:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long final_step(long long *n, int *len, char **res)
{
	int		i;

	if (*n < 0)
	{
		if (!((*res) = ft_strnew(*len + 1)))
			return (0);
		res[0][0] = '-';
		*n = -(*n);
		i = 1;
		*len += 1;
	}
	else
	{
		i = 0;
		(*res) = ft_strnew(*len);
	}
	return (i);
}

static char	*exceptions(long long n)
{
	char 		*res;
	long long	min_long;

	min_long = -9223372036854775807 - 1;
	if (n == min_long)
	{
		if (!(res = ft_strnew(11)))
			return (NULL);
		res = ft_strcat(ft_strcpy(res, ft_ltoa(-922337203685477580)), ft_itoa(8));
	}
	if (n == 0)
	{
		if (!(res = ft_strnew(1)))
			return (NULL);
		res[0] = 0 + 48;
	}
	return (res);
}

char		*ft_lltoa(long long n)
{
	int			digit;
	char		*res;
	long long	i;

	digit = 0;
	if (n == -2147483648 || n == 0)
	{
		res = exceptions(n);
		return (res);
	}
	i = n;
	while (i)
	{
		digit++;
		i /= 10;
	}
	i = final_step(&n, &digit, &res);
	if (!res)
		return (NULL);
	while ((digit - 1) >= i)
	{
		res[(digit--) - 1] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
