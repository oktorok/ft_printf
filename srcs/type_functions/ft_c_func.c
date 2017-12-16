/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:50:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/16 05:46:23 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, int minus, char *variab)
{
	char	*tmp;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (minus)
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else	
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	return (tmp);
}

char			*ft_c_func(char *comm, va_list ap)
{
	int		siz_cuant[2];
	char	*variable;
	void	*mod_variable;
	char	*res;

	siz_cuant[1] = 0;
	variable = ft_strnew(2);
	variable[0] = va_arg(ap, int);
	mod_variable = ft_l_func(siz_cuant, comm, (void *)variable);
	if (mod_variable)
	{
		ft_strdel(&variable);
		variable = (char *)mod_variable;
	}
	ft_field_func(siz_cuant, comm, variable);
	res = writer(siz_cuant, ft_minus_func(comm), variable);
	mod_variable = (char *)mod_variable;
	ft_strdel((char **)(&mod_variable));
	return (res);
}
