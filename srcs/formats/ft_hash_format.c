/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/29 23:16:19 by jagarcia         ###   ########.fr       */
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

static char	*b_hash(char *variable, int *siz_cuant)
{
	char	*aux;
	char 	*var_head;
	int		i;
	int		j;

	if (ft_strlen(variable) % 4)
		i = ft_strlen(variable) + (ft_strlen(variable) / 4 - 1)
			+ (ft_strlen(variable) / 8 - 1);	
	else
		i = ft_strlen(variable) + (ft_strlen(variable) / 4)
			+ (ft_strlen(variable) / 8);
	aux = ft_strnew(i);
	var_head = variable;
	variable += ft_strlen(variable) - 1;
	while (i >= 0)
	{
		aux[i--] = *variable--;
		j++;
		if (!(j % 4))
			aux[i--] = ' ';
		if (!(j % 8))
			aux[i--] = ' ';
	}
	variable++;
	ft_strdel(&variable);
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
