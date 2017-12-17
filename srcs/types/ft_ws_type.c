/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/17 03:41:27 by jagarcia         ###   ########.fr       */
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

char			*ft_ws_type(char *comm, va_list ap)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

	siz_cuant[1] = 0;
	variable = ft_wchar((void *)va_arg(ap, wchar_t *), siz_cuant, comm);
	ft_field_format(siz_cuant, comm, variable);
	res = writer(siz_cuant, ft_minus_format(comm), variable);
	variable = (char *)variable;
	ft_strdel((char **)(&variable));
	return (res);
}
