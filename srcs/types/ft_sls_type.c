/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sls_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 02:31:24 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (-1);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	if (ft_mods(comm) == 2 || !(ft_strcmp(variab, "(null)")))
		ft_strdel(&variab);
	return (tmp);
}

static void		ajust_cuant_size(int *siz_cuant, char *variable)
{
	int len;

	len = ft_strlen(variable);
	if (siz_cuant[1] > len || siz_cuant[1] < 0)
		siz_cuant[1] = len;
	if ((!siz_cuant[0] || siz_cuant[0] < len) && siz_cuant[1])
		siz_cuant[0] = siz_cuant[1];
}

int				ft_sls_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	if (ft_mods(comm) == 2 || ft_strchr(comm, 'S'))
	{
		if (!(variable = ft_wchar(ap[0], ap[1], siz_cuant, comm)))
			return (-1);
	}
	else
		if (!(variable = (char *)ft_locate_pointer(comm, ap[0], ap[1])))
			return (-1);
	if (!variable && !ft_strchr(comm, 'S'))
	{
		ft_strdel(&variable);
		if (!(variable = ft_strnew(6)))
			return (-1);
		ft_strcpy(variable, "(null)");
	}
	else if (!variable && ft_strchr(comm, 'S'))
		return (-1);
	ajust_cuant_size(siz_cuant, variable);
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
