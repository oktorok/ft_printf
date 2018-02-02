/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:50:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/02 21:54:12 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	return (tmp);
}

char			*ft_clc_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (ft_mods(comm) == 2 || ft_strchr(comm, 'C'))
	{
		if (!(variable = ft_wchar(ap, ap2, siz_cuant, comm)))
			return (NULL);
	}
	else
		variable = (char *)ft_locate_date(comm, 1, ap, ap2);
	if (siz_cuant[1] > ft_strlen(variable) || siz_cuant[1] < 0)
		siz_cuant[1] = ft_strlen(variable);
	if (!siz_cuant[0])
		siz_cuant[0] = siz_cuant[1];
	res = writer(siz_cuant, comm, variable);
	return (res);
}
