/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 01:07:30 by jagarcia         ###   ########.fr       */
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
	ft_strdel(&variab);
	return (tmp);
}

char			*ft_ws_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (!(variable = (char *)ft_wchar(ap, ap2, siz_cuant, comm)))
		return (NULL);
	if (siz_cuant[1] > ft_strlen(variable) || siz_cuant[1] < 0)
		siz_cuant[1] = ft_strlen(variable);
	if ((!siz_cuant[0] || siz_cuant[0] < ft_strlen(variable)) && siz_cuant[1])
		siz_cuant[0] = siz_cuant[1];
	res = writer(siz_cuant, ft_minus_format(comm), variable);
	return (res);
}
