/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 19:11:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/16 23:59:01 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_binsize(char *n, size_t len, size_t *i, char *j)
{
	*i = len - 1;
	*j = 0;
	while (!(n[*i] & (0x80 >> (*j))) && (*i + 1) > 0)
	{
		(*j)++;
		if (*j == 8)
		{
			(*i)--;
			(*j) = 0;
		}
	}
	return (ft_strnew(sizeof(char) * ((len * 8)
				- ((((len - 1) - *i) * 8) + (*j)))));
}

char	*ft_dectobin(void *num, size_t len)
{
	char	*n;
	char	*str;
	size_t	i;
	size_t	k;
	char	j;

	n = (char *)num;
	str = ft_binsize(n, len, &i, &j);
	if (!str)
		return (NULL);
	k = 0;
	while (i < len)
	{
		while (j < 8)
		{
			str[k] = '0';
			if ((n[i] & (0x80 >> j)))
				str[k++] = '1';
			j++;
		}
		j = 0;
		i--;
	}
	ft_memdel(&num);
	return (str);
}
