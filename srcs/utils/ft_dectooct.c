/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectooct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 23:11:18 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/31 17:29:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
//////////////////
	if (i < 0)
		i = 0;
/////////////////
	*s_len = ((len * 8) - ((((len - 1) - i) * 8) + (j)));
	ft_putchar('\n');
	if ((*s_len % 3))
		*s_len = 1 + (*s_len / 3);
	else
		(*s_len) /= 3;
	return (ft_strnew(sizeof(char) * (*s_len) - 1));
}

size_t	ft_rd1(char *n, size_t i, size_t *j)
{
	if ((i % 8) == 0)
		return ((n[*j] & 0x7) + 48);
	if ((i % 8) == 1)
		return (((n[(*j)++] & 0x38) >> 3) + 48);
	if ((i % 8) == 2)
		return ((((n[*j] & 0x1) << 2) + ((n[(*j) - 1] & 0xC0) >> 6)) + 48);
	if ((i % 8) == 3)
		return (((n[*j] & 0xE) >> 1) + 48);
	if ((i % 8) == 4)
		return (((n[(*j)++] & 0x70) >> 4) + 48);
	if ((i % 8) == 5)
		return ((((n[*j] & 0x3) << 1) + ((n[(*j) - 1] & 0x80) >> 7)) + 48);
	if ((i % 8) == 6)
		return (((n[*j] & 0x1C) >> 2) + 48);
	return (((n[(*j)++] & 0xE0) >> 5) + 48);
}

char	*ft_dectooct(void *num, size_t len)
{
	char	*n;
	char	*str;
	size_t	i;
	size_t	s_len;
	size_t	j;

	n = (char *)num;
	if (!(str = ft_octsize(n, len, &s_len)))
		return (NULL);
	i = 0;
	j = 0;
	s_len--;
	while ((s_len + 1) > 0)
		str[s_len--] = ft_rd1(n, i++, &j);
	ft_putchar(*(str - 1));
	return (str);
}