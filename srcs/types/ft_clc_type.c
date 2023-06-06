/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:50:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/07 23:24:53 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	if (ft_search_zero_format(comm) && !ft_minus_format(comm))
	{
		tmp = ft_memset(ft_strnew(siz_cuant[0]), '0', siz_cuant[0]);
		if (!tmp)
			return (NULL);
	}
	else
	{
		tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
		if (!tmp)
			return (NULL);
	}
	if (ft_minus_format(comm))
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	ft_strdel(&variab);
	ft_strdel(&comm);
	return (tmp);
}

static int	locate_date(char *comm, va_list *ap, char **variable)
{
	char	*tmp;

	tmp = (char *)ft_locate_date(comm, 1, ap, ap+1);
	if (!tmp)
		return (0);
	*variable = ft_memcpy(ft_strnew(1), tmp, 1);
	free(tmp);
	return (1);
}

int	ft_clc_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, &comm, ap);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (ft_mods(comm) == 4 || ft_strchr(comm, 'C'))
	{
		variable = ft_wchar(ap, ap+1, siz_cuant, comm);
		if (!variable)
			return (-1);
	}
	else if (!locate_date(comm, ap, &variable))
		 return (-1);
	ft_ajust_params(siz_cuant, variable, comm);
	variable = writer(siz_cuant, comm, variable);
	if (!variable)
		return (-1);
	*res = ft_memjoinfree(*res, variable, len, siz_cuant[0]);
	if (!*res)
		return (-1);
	return (len + siz_cuant[0]);
}
