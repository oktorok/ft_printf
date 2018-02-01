/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 20:24:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_zeros(char *variable, int *siz_cuant)
{
	if (!(siz_cuant[0] < ft_strlen(variable)) && !siz_cuant[1])
	{
		if ((*variable == '0') && (*(variable + 1) == '0')
			&& *(variable + 2) && siz_cuant[0] == ft_strlen(variable))
			return (2);
	}
	return (0);
}

static char	*ox_hash(char *variable, int *siz_cuant, int type)
{
	char *aux;

	if (type == 'o')
	{
		aux = ft_strnew(ft_strlen(variable) + 1);
		*aux++ = '0';
		siz_cuant[0]++;
		ft_strcpy(aux, variable);
		ft_strdel(&variable);
		return (--aux);
	}
	else if (type == 'x')
	{
		aux = ft_strnew(ft_strlen(variable) + 2);
		*aux++ = '0';
		*aux++ = 'x';
		ft_strcpy(aux, variable + check_zeros(variable, siz_cuant));
		ft_strdel(&variable);
		if (siz_cuant[0] < ft_strlen(aux - 2))
			siz_cuant[0] += 2;
		return (aux - 2);
	}
	return (variable);
}

static char	*b_hash(char *var, int *siz_cuant)
{
	char	*aux;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(var) + (ft_strlen(var) / 4) + (ft_strlen(var) / 8 * 2);
	if (!(ft_strlen(var) % 4))
		i -= 3;
	siz_cuant[0] += i - ft_strlen(var);
	aux = ft_strnew(i--);
	var += ft_strlen(var) - 1;
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
	int		i;

	i = 0;
	while (command[i] != '#')
		if (!(command[i++]))
			return (variable);
	if (ft_toupper((command[ft_strlen(command) - 1])) == 'O')
		return (ox_hash(variable, siz_cuant, 'o'));
	if (ft_toupper((command[ft_strlen(command) - 1])) == 'X')
		return (ox_hash(variable, siz_cuant, 'x'));
	if (command[ft_strlen(command) - 1] == 'b')
		return (b_hash(variable, siz_cuant));
	return (variable);
}
