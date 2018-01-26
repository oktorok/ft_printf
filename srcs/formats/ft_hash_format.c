/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:07:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/26 16:11:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_hash_format(char *command, char *variable)
{
	char *aux;

	if ((command[ft_strlen(command) - 1] == 'o') ||
		(command[ft_strlen(command) - 1] == 'O'))
	{
		aux = ft_strnew(ft_strlen(variable) + 1);
		*aux++ = '0';
		ft_strcpy(aux, variable);
		ft_strdel(&variable);
		return (--aux);
	}	
	if (command[ft_strlen(command) - 1] == 'x')
	{
		aux = ft_strnew(ft_strlen(variable) + 1);
		*aux++ = '0';
		*aux++ = 'x';
		ft_strcpy(aux, variable);
		ft_strdel(&variable);
		return (aux - 2);
	}
	if (command[ft_strlen(command) - 1] == 'X')
	{
		aux = ft_strnew(ft_strlen(variable) + 1);
		*aux++ = '0';
		*aux++ = 'X';
		ft_strcpy(aux, variable);
		ft_strdel(&variable);
		return (aux - 2);
	}
	return (variable);
}
