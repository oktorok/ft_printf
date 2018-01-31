/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/31 20:10:01 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		size(char **command, va_list ap, va_list ap2)
{
	char	*aux;
	int		*tmp;

	while ((!ft_isdigit(**command) || **command == '0') && **command != '*'
			&& **command != '.' && **command)
		(*command)++;
	aux = *command;
	while (ft_isdigit(**command) && **command)
		(*command)++;
	if (**command == '$' || **command == '0')
		return (-1);
	if (**command == '*')
	{
		if (ft_isdigit(*(*command + 1)))
		{
			tmp = (int *)ft_locate_date(*command + 1, 5, ap, ap2);
			return (*tmp);
		}
		return (va_arg(ap2, int));
	}
	return (ft_atoi(aux));
}

static int		cuant(char *command, va_list ap, va_list ap2)
{
	char	*aux;
	int		*tmp;

	if ((aux = ft_strchr(command, '.')))
	{
		if (*(aux + 1) == '*')
		{
			if (ft_isdigit(*(aux + 2)))
			{
				tmp = (int *)ft_locate_date(aux + 2, 5, ap, ap2);
				return (*tmp);
			}
			return (va_arg(ap2, int));
		}
		return (ft_atoi(aux + 1));
	}
	return (-1);
}

void			ft_field_format(int *size_cuant,
		char *command, va_list ap, va_list ap2)
{
	size_cuant[0] = -1;
	while (size_cuant[0] < 0)
		size_cuant[0] = size(&command, ap, ap2);
	size_cuant[1] = cuant(command, ap, ap2);
}
