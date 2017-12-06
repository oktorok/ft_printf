/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:12:45 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/21 00:09:25 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	numlen(const char *str2)
{
	char	*str2cpy;
	size_t	len;

	len = 0;
	str2cpy = (char *)str2;
	while ((*(str2cpy + 1) >= '0' && *(str2cpy + 1) <= '9'))
	{
		str2cpy++;
		len++;
	}
	return (len);
}

static	int		jumps(char **s)
{
	int a;

	a = 1;
	while (**s == ' ' || (**s == '+' && (*((*s) + 1)
						>= '0' && *((*s) + 1) <= '9')) || **s == '\v'
				|| **s == '\n' || **s == '\t' || **s == '\f'
				|| **s == '\r')
		(*s)++;
	if (**s == '-' && (*(*s + 1) >= '0' && *(*s + 1) <= '9'))
	{
		a = -1;
		(*s)++;
	}
	return (a);
}

int				ft_atoi(const char *str)
{
	char	*strcpy;
	int		res;
	size_t	len;
	int		i[2];

	strcpy = (char *)str;
	i[1] = jumps(&strcpy);
	if (*strcpy < '0' || *strcpy > '9')
		return (0);
	len = numlen(strcpy);
	res = 0;
	i[0] = len;
	while (i[0] >= 0)
	{
		res = res + ((strcpy[i[0]] - 48) * ft_pow(10, (len) - i[0]));
		i[0]--;
	}
	return (i[1] * res);
}
