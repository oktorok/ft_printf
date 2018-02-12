/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:50:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/12 13:20:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (NULL);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	ft_strdel(&variab);
	return (tmp);
}

int				ft_clc_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (ft_mods(comm) == 2 || ft_strchr(comm, 'C'))
	{
		if (!(variable = ft_wchar(ap[0], ap[1], siz_cuant, comm)))
			return (-1);
	}
	else
		if (!(variable = (char *)ft_locate_date(comm, 1, ap[0], ap[1])))
			return (-1);
	ft_ajust_params(siz_cuant, variable, comm);
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
