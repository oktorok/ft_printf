/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 08:28:56 by jagarcia         ###   ########.fr       */
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
	if (!(new_variable = ft_strnew(size)))
		return (-1);
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

	if (!(variable = (char *)ft_locate_pointer(comm, ap, ap2)))
		return (-1);
	if (!(variable = non_printable(variable)))
		return (-1);
	if (!(*res = ft_strjoinfree(*res, variable)))
		return (-1);
	len_com = ft_strlen(*res);
	return (len_com);
}
