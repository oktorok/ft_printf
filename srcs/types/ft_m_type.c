/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 23:27:59 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/19 10:38:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_m_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;
	int		len_var;

	ft_field_format(siz_cuant, &comm, ap);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	variable = ft_printmemory(ft_locate_pointer(comm, ap, ap+1),
			siz_cuant[0]);
	if (!variable)
		return (-1);
	len_var = ft_strlen(variable);
	*res = ft_memjoinfree(*res, variable, len, len_var);
	if (!*res)
		return (-1);
	return (len + len_var);
}
