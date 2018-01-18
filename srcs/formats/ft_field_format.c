/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/18 22:17:53 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		size(char **command, va_list ap, va_list ap2)
{
	char *aux;

	while (!ft_isdigit(**command) && **command != '*' && **command != '.' && **command)
		(*command)++;
	aux = *command;
	while (ft_isdigit(**command) && **command)
		(*command)++;
	if (**command == '$')
		return (-1);
	if (**command == '*')
	{
		if (ft_isdigit(*(*command + 1)))
			return ((int)ft_locate_variable(*command + 1, ap, ap2));
		return (va_arg(ap2, int));
	}
	return (ft_atoi(aux));
}

static int		cuant(char *command, va_list ap, va_list ap2)
{
	char *aux;

	if ((aux = ft_strchr(command, '.')))
	{
		if (*(aux + 1) == '*')
		{
			if (ft_isdigit(*(aux + 2)))
				return ((int)ft_locate_variable(aux + 2, ap, ap2));
			return (va_arg(ap2, int));
		}
		return (ft_atoi(aux + 1));
	}
	return (-1);
}
void			ft_field_format(int *size_cuant, char *command, va_list ap, va_list ap2)
{	
	size_cuant[0] = -1;
	while (size_cuant[0] < 0)
		size_cuant[0] = size(&command, ap, ap2);
	size_cuant[1] = cuant(command, ap, ap2);
}
