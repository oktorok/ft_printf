/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectooct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:11:18 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/29 22:18:13 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"
#include<stdio.h>
char	*ft_octsize(char *n, size_t len, size_t *s_len)
{
	int		i;
	char	j;

	i = len - 1;
	j = 0;
	while (!(n[i] & (0x80 >> (j))))
	{
		(j)++;
		if (j == 8)
		{
			(i)--;
			(j) = 0;
		}
	}
	*s_len = ((len * 8) - ((((len - 1) - i) * 8) + (j)));
	if ((*s_len % 3))
		*s_len = 1 + (*s_len / 3);
	else
		(*s_len) /= 3;
	return (ft_strnew(sizeof(char) * (*s_len)));
}

size_t	ft_rd1(char *n, size_t i, char *str, size_t s_len)
{
	str[s_len--] = (n[i] & 0x7) + 48;
	str[s_len--] = ((n[i] & 0x38) >> 3) + 48;
	return (s_len);
}

size_t	ft_rd2(char *n, size_t i, char *str, size_t s_len)
{
	str[s_len--] = (((n[i] & 0x1) << 2) + ((n[i - 1] & 0xC0) >> 6)) + 48;
	str[s_len--] = ((n[i] & 0xE) >> 1) + 48;
	str[s_len--] = ((n[i] & 0x70) >> 4) + 48;
	return (s_len);
}

size_t	ft_rd3(char *n, size_t i, char *str, size_t s_len)
{
	str[s_len--] = (((n[i] & 0x3) << 1) + ((n[i - 1] & 0x80) >> 7)) + 48;
	str[s_len--] = ((n[i] & 0x1C) >> 2) + 48;
	str[s_len--] = ((n[i] & 0xE0) >> 5) + 48;
	return (s_len);
}

char	*ft_dectooct(void *num, size_t len)
{
	char	*n;
	char	*str;
	size_t	i;
	size_t	s_len;

	n = (char *)num;
	if (!(str = ft_octsize(n, len, &s_len)))
		return (NULL);
	i = 0;
	s_len--;
	while (i < len)
	{
		s_len = ft_rd1(n, i, str, s_len);
		if (++i < len)
			s_len = ft_rd2(n, i, str, s_len);
		if (++i < len)
			s_len = ft_rd3(n, i, str, s_len);
		i++;
	}
//	if ((((len * 8) % 24) % 3) == 1)
//		str[0] = ((n[len - 1] & 0x80) >> 7) + 48;
//	else if ((((len * 8) % 24) % 3) == 2)
//		str[0] = ((n[len - 1] & 0xC0) >> 6) + 48;
	return (str);
}
