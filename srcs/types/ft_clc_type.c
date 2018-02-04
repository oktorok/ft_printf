/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clc_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:50:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/04 08:40:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		writer(int *siz_cuant, char *comm, char *variab, char **res)
{
	char	*tmp;
	int		len_com;
	char	*res_aux;

	if (!*variab)
		len_com = 1;
	else
		len_com = 0;
	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, siz_cuant[1]);
	else
		ft_strncpy(tmp + siz_cuant[0] - siz_cuant[1], variab, siz_cuant[1]);
	ft_strdel(&variab);
	len_com += ft_strlen(tmp);
	res_aux = ft_strcpy(ft_strnew(ft_strlen(*res) + len_com), *res);
	ft_strcat(res_aux, tmp);
	ft_strdel(res);
	*res = res_aux;
	return (len_com);
}

static void		ajust_cuant_size(int *siz_cuant, char *variable)
{
	if (siz_cuant[1] > 1 || siz_cuant[1] <= 0)
		siz_cuant[1] = 1;
	if (!siz_cuant[0])
		siz_cuant[0] = siz_cuant[1];
}

int				ft_clc_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (ft_mods(comm) == 2 || ft_strchr(comm, 'C'))
	{
		if (!(variable = ft_wchar(ap, ap2, siz_cuant, comm)))
			return (-1);
	}
	else
		variable = (char *)ft_locate_date(comm, 1, ap, ap2);
	ajust_cuant_size(siz_cuant, variable);
	return (writer(siz_cuant, comm, variable, res));
}
