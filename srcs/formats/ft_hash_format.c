/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/27 01:31:21 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_hash_format(char *command, char *variable, int *siz_cuant)
{
	char	*aux;
	int		i;

	i = 0;
	while (command[i] != '#')
		if (!(command[i++]))
			return (variable);
	if ((command[ft_strlen(command) - 1] == 'o') ||
		(command[ft_strlen(command) - 1] == 'O'))
	{
		aux = ft_strnew(ft_strlen(variable) + 1);
		*aux++ = '0';
		siz_cuant[0]++;
		ft_strcpy(aux, variable);
		ft_strdel(&variable);
		return (--aux);
	}	
	if ((command[ft_strlen(command) - 1] == 'x') ||
		(command[ft_strlen(command) - 1] == 'X'))
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
