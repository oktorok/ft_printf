/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sls_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 06:03:05 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		writer(int *siz_cuant, char *comm, char *variab, char **res)
{
	char	*tmp;
	int		len_com;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	if (ft_mods(comm) == 2 || !(ft_strcmp(variab, "(null)")))
		ft_strdel(&variab);
//	len_com = ft_strlen(tmp);
	*res = ft_strjoinfree(*res, tmp);
	len_com = ft_strlen(*res);
	return (len_com);
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

int				ft_sls_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (ft_mods(comm) == 2 || ft_strchr(comm, 'S'))
		variable = ft_wchar(ap, ap2, siz_cuant, comm);
	else
		variable = (char *)ft_locate_pointer(comm, ap, ap2);
	if (!variable && !ft_strchr(comm, 'S'))
	{
		ft_strdel(&variable);
		variable = ft_strnew(6);
		ft_strcpy(variable, "(null)");
	}
	else if (!variable && ft_strchr(comm, 'S'))
		return (-1);
	ajust_cuant_size(siz_cuant, variable);
	return (writer(siz_cuant, comm, variable, res));
}
