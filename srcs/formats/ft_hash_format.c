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

static char	*b_hash(char *var, int len)
{
	char	*aux;
	int		i;
	int		j;

	j = 0;
	i = len + (len / 4) + (len / 8 * 2);
	if (!(len % 4))
		i -= 3;
	aux = ft_strnew(i--);
	if (!aux)
		return (NULL);
	var += len - 1;
	while (i >= 0)
	{
		aux[i--] = *var--;
		if (!(++j % 4))
			aux[i--] = ' ';
		if (!(j % 8))
		{
			aux[i--] = '|';
			aux[i--] = ' ';
		}
	}
	var++;
	return (aux);
}

static char	*fge_hash(char *var, int *siz_cuant)
{
	int	pos;

	if (!siz_cuant[1])
	{
		pos = 0;
		while (ft_isdigit(var[pos]) || var[pos] == '-')
			pos++;
		var = ft_strinsertfree(var, ft_strdup("."), pos);
		if (!var)
			return (NULL);
		siz_cuant[0]++;
	}
	return (var);
}

char	*ft_hash_format(char *command, char *variable, int *siz_cuant)
{
	int		len;
	char	comm;
	char	*aux;

	comm = ft_toupper((command[ft_strlen(command) - 1]));
	len = ft_strlen(variable);
	if (!(ft_strchr(command, '#')))
		return (variable);
	if (comm == 'O')
		return (ox_hash(variable, siz_cuant, 'o', len));
	if (comm == 'X')
		return (ox_hash(variable, siz_cuant, 'x', len));
	if (comm == 'F' || comm == 'E' || comm == 'G')
		return (fge_hash(variable, siz_cuant));
	if (comm == 'b')
	{
		siz_cuant[0] += len / 4 + len / 8 * 2;
		aux = b_hash(variable, len);
		ft_strdel(&variable);
		return (aux);
	}
	return (variable);
}
