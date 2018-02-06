/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 02:35:26 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_zeros(char *variable, int *siz_cuant)
{
	if (!(siz_cuant[0] < ft_strlen(variable)) && !siz_cuant[1])
	{
		if (siz_cuant[0] == 2 && *variable == '0')
			return (1);
		if ((*variable == '0') && (*(variable + 1) == '0')
			&& *(variable + 2) && siz_cuant[0] == ft_strlen(variable))
			return (2);
	}
	return (0);
}

static char	*ox_hash(char *variable, int *siz_cuant, int type, int len)
{
	char *aux;

	if (type == 'o')
	{
		if (!(aux = ft_strnew(len + 1)))
			return (NULL);
		*aux++ = '0';
		ft_strcpy(aux, variable + check_zeros(variable, siz_cuant));
		ft_strdel(&variable);
		if (siz_cuant[0] < len + 1)
			siz_cuant[0] += 1;
		return (--aux);
	}
	else if (type == 'x')
	{
		if (!(aux = ft_strjoin("0x", variable + check_zeros(variable,
							siz_cuant))))
			return (NULL);
		if (siz_cuant[0] < len + 2)
			siz_cuant[0] = len + 2;
		ft_strdel(&variable);
		return (aux);
	}
	return (variable);
}

static char	*b_hash(char *var, int len)
{
	char	*aux;
	int		i;
	int		j;

	j = 0;
	i = len + (len / 4) + (len / 8 * 2);
	if (!(len % 4))
		i -= 3;
	if (!(aux = ft_strnew(i--)))
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
	ft_strdel(&var);
	return (aux);
}

char	*ft_hash_format(char *command, char *variable, int *siz_cuant)
{
	int		len;

	len = ft_strlen(variable);
	if (!(ft_strchr(command, '#')))
		return (variable);
	if (ft_toupper((command[ft_strlen(command) - 1])) == 'O')
		return (ox_hash(variable, siz_cuant, 'o', len));
	if (ft_toupper((command[ft_strlen(command) - 1])) == 'X')
		return (ox_hash(variable, siz_cuant, 'x', len));
	if (command[ft_strlen(command) - 1] == 'b')
	{
		siz_cuant[0] += len /4 + len/ 8 * 2;
		return (b_hash(variable, len));
	}
	return (variable);
}
