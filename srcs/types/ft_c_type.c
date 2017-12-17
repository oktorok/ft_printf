/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:50:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/17 03:40:12 by jagarcia         ###   ########.fr       */
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

char			*ft_c_type(char *comm, va_list ap)
{
	int		siz_cuant[2];
	int		*variable;
	void	*mod_variable;
	char	*res;

	siz_cuant[1] = 0;
	variable = ft_memalloc(5);
	*variable = va_arg(ap,int);
	mod_variable = ft_l_mod(siz_cuant, comm, (void *)variable);
	if (mod_variable)
	{
		ft_memdel((void **)&variable);
		variable = (int *)mod_variable;
	}
	ft_field_format(siz_cuant, comm, (char *)variable);
	siz_cuant[1] = 1;
	res = writer(siz_cuant, ft_minus_format(comm), (char *)variable);
	mod_variable = (char *)mod_variable;
	ft_strdel((char **)(&mod_variable));
	return (res);
}
