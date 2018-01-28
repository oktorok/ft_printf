/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:08:05 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/28 20:02:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*ft_hexsize(char *n, size_t len, size_t *s_len)
{
	size_t	i;
	char	j;

	i = len - 1;
	j = 0;
	while (!(n[i] & (0xF0 >> j)))
	{
		j += 4;
		if (j == 8)
		{
			(i)--;
			(j) = 0;
		}
	}
	*s_len = (((len * 8) - ((((len - 1) - i) * 8) + (j))) / 4) - 1;
	return (ft_strnew(sizeof(char) * (*s_len + 1)));
}

char	*ft_dectohex(void *num, size_t len)
{
	char	*n;
	char	*str;
	size_t	i;
	size_t	s_len;

	n = (char *)num;
	if (!(str = ft_hexsize(n, len, &s_len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[s_len] = n[i] & 0xF;
		str[s_len - 1] = (n[i] & 0xF0) >> 4;
		if (str[s_len] >= 10)
			str[s_len] = str[s_len] + 'a' - 10;
		else
			str[s_len] = str[s_len] + 48;
		if (str[s_len - 1] >= 10)
			str[s_len - 1] = str[s_len - 1] + 'a' - 10;
		else
			str[s_len - 1] = str[s_len - 1] + 48;
		s_len -= 2;
		i++;
	}
	return (str);
}
