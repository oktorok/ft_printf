/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:08:05 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/12 15:26:05 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char	*ft_hexsize(char *n, size_t len, size_t *s_len)
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
	*s_len = 1;
	if ((len * 2) - k)
		*s_len = ((len * 2) - k);
	return (ft_strnew(sizeof(char) * (*s_len)));
}

static char	*for_p(char *str, char *comm, void *num)
{
	if (!ft_strchr(comm, 'p'))
		ft_memdel(&num);
	return (str);
}

char	*ft_dectohex(void *num, size_t len, char *comm)
{
	size_t	k;
	char	*str;
	size_t	i;
	size_t	aux;

	str = ft_hexsize((char *)num, len, &aux);
	if (!str)
		return (NULL);
	i = 0;
	aux = aux - 1;
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
	return (for_p(str, comm, num));
}
