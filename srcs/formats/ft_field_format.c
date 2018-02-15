/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/15 17:50:27 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		take_num(char *command, int i, va_list ap, va_list ap2)
{
	void	*tmp;
	int		aux;

	if (ft_isdigit(command[i + 1]))
	{
		if (!(tmp = ft_locate_date(command + i + 1, 5, ap, ap2)))
			return (-2);
		aux = *((int *)tmp);
		ft_memdel(&tmp);
		return (aux);
	}
	return (va_arg(ap2, int));
}

static int		take_size(char *command, va_list ap, va_list ap2)
{
	int		len;
	
	len = ft_strlen(command) - 1;
	while (len >= 0)
	{
		if (command[len] == '$')
			while (ft_isdigit(command[--len]) && len >= 0);
		if (command[len] == '*')
			break ;
		else if (ft_isdigit(command[len]))
		{
			while (ft_isdigit(command[len]) && len >= 0)
				len--;
			if (command[len] != '.')
			{
				len++;
				break ;
			}
		}
		if (command[len] != '$' && len >= 0)
			len--;
	}
	if (command[len] == '*')
		return (take_num(command, len, ap, ap2));
	return (ft_atoi(command + len));
}

static int		take_cuant(char *command, va_list ap, va_list ap2)
{
	int		len;

	len = ft_strlen(command) - 1;
	while (command[len] != '.' && len >= 0)
		len--;
	if (len >= 0)
	{
		if (command[len + 1] == '*')
			return (take_num(command, len, ap, ap2));
		return (ft_atoi(command + len + 1));
	}
	return (-1);
}

void			ft_field_format(int *size_cuant,
		char *command, va_list ap, va_list ap2)
{
	size_cuant[1] = take_cuant(command, ap, ap2);
	size_cuant[0] = take_size(command, ap, ap2);

}
