/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/08 19:07:17 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_zeros(char *variable, int *siz_cuant)
{
	if (!((unsigned long)siz_cuant[0]
			< ft_strlen(variable)) && siz_cuant[1] == -1)
	{
		if (*variable == '0' && *(variable + 1) && *(variable + 1) != '0')
			return (1);
		if ((*variable == '0') && (*(variable + 1) == '0')
			&& *(variable + 2)
			&& (unsigned long)siz_cuant[0] == ft_strlen(variable))
			return (2);
	}
	return (0);
}

static char	*x_type(char *variable, int zeros, int len, int *siz_cuant)
{
	char	*aux;

	aux = ft_strjoin("0x", variable + zeros);
	if (!aux)
		return (NULL);
	if (siz_cuant[0] < len + 2 - zeros)
		siz_cuant[0] = len + 2 - zeros;
	ft_strdel(&variable);
	return (aux);
}

char	*ox_hash(char *variable, int *siz_cuant, int type, int len)
{
	char	*aux;
	int		zeros;

	zeros = check_zeros(variable, siz_cuant);
	if (type == 'o')
	{
		aux = ft_strnew(len + 1);
		if (!aux)
			return (NULL);
		*aux++ = '0';
		ft_strcpy(aux, variable + zeros);
		ft_strdel(&variable);
		if (siz_cuant[0] < len + 1)
			siz_cuant[0] += 1;
		return (--aux);
	}
	else if (type == 'x')
		return (x_type(variable, zeros, len, siz_cuant));
	return (variable);
}
