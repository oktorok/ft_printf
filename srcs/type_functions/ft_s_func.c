/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 02:41:59 by mrodrigu         ###   ########.fr       */
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

char			*ft_s_func(char *comm, va_list ap)
{
	int		siz_cuant[2];
	char	*variable;
	void	*mod_variable;
	va_list	ap2;

	siz_cuant[1] = 0;
	va_copy(ap2, ap);
	variable = va_arg(ap, char *);
	mod_variable = ft_l_func(siz_cuant, comm, ap2);
	if (mod_variable)
		variable = (char *)mod_variable;
	ft_field_func(siz_cuant, comm, variable);
	va_end(ap2);
	return (writer(siz_cuant, ft_minus_func(comm), variable));
}
