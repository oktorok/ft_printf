/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 06:27:36 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*non_printable(char *variable)
{
	int		i;
	char	*new_variable;
	int		size;

	i = 0;
	size = 0;
	while (i < ft_strlen(variable) + 1)
		size += ft_strlen(g_symbols[variable[i++]]);
	ft_putnbr(size);
	new_variable = ft_strnew(size);
	i = 0;
	while (i < ft_strlen(variable) + 1)
		ft_strcat(new_variable, g_symbols[variable[i++]]);
	return (new_variable);
}

int			ft_r_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;
	int		len_com;

	variable = (char *)ft_locate_pointer(comm, ap, ap2);
	variable = non_printable(variable);
	len_com = ft_strlen(variable);
	*res = ft_strjoinfree(*res, variable);
	return (len_com);
}
