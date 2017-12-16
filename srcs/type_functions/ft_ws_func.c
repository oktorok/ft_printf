/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 06:04:07 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, int minus, char *variab)
{
	char	*tmp;

	if (siz_cuant[0] == 0)
		return (NULL);
	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (minus)
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else	
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	return (tmp);
}

char			*ft_ws_func(char *comm, va_list ap)
{
	int		siz_cuant[2];
	char	*variable;
	void	*mod_variable;
	char	*res;

	siz_cuant[1] = 0;
	variable = ft_wchartype((void *)va_arg(ap, wchar_t *), siz_cuant, comm);
	ft_field_func(siz_cuant, comm, variable);
	res = writer(siz_cuant, ft_minus_func(comm), variable);
	variable = (char *)variable;
	ft_strdel((char **)(&variable));
	return (res);
}
