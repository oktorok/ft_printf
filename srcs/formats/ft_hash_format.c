/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/30 01:45:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		siz_cuant[0] += 2;
		ft_strcpy(aux, variable);
		ft_strdel(&variable);
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
