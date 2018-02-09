/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:08:05 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/09 03:43:18 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*ft_hexsize(char *n, size_t len, size_t *s_len)
{
	long	i;
	size_t	j;
	size_t	k;

	i = len - 1;
	j = 0;
	k = 0;
	while (j < len)
	{
		if (!(n[i] & 0xF0))
			k++;
		else
			break ;
		if (!(n[i] & 0xF))
			k++;
		else
			break ;
		i--;
		j++;
	}
	*s_len = ((len * 2) - k) ? ((len * 2) - k) : 1;
	return (ft_strnew(sizeof(char) * (*s_len)));
}

char	*ft_dectohex(void *num, size_t len, char *comm)
{
	size_t	k;
	char	*str;
	size_t	i;
	size_t	s_len;
	size_t	aux;

	if (!(str = ft_hexsize((char *)num, len, &s_len)))
		return (NULL);
	i = 0;
	aux = s_len - 1;
	k = 0;
	while ((aux + 1) > 0)
	{
		str[aux] = (((char *)num)[i] & (0xF << (4 * k))) >> (4 * k);
		if (str[aux] >= 10)
			str[aux] = str[aux] + 'a' - 10;
		else
			str[aux] = str[aux] + 48;
		aux--;
		if (k--)
			i++;
		else
			k = 1;
	}
	if (!ft_strchr(comm, 'p'))
		ft_memdel(&num);
	return (str);
}
