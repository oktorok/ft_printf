/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 15:27:37 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*non_printable(char *variable)
{
	size_t	i;
	char	*new_variable;
	int		size;

	i = 0;
	size = 0;
	while (i < ft_strlen(variable) + 1)
		size += ft_strlen(g_symbols[(int)variable[i++]]);
	if (!(new_variable = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(variable) + 1)
		ft_strcat(new_variable, g_symbols[(int)variable[i++]]);
	return (new_variable);
}

int				ft_r_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	if (!(variable = (char *)ft_locate_pointer(comm, ap[0], ap[1])))
		return (-1);
	if (!(variable = non_printable(variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
