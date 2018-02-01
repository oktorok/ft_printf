/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sls_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 22:57:31 by jagarcia         ###   ########.fr       */
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
	if (ft_mods(comm) == 2)
		ft_strdel(&variab);
	return (tmp);
}

char			*ft_sls_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

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
		return (NULL);
	if (siz_cuant[1] > ft_strlen(variable) || siz_cuant[1] < 0)
		siz_cuant[1] = ft_strlen(variable);
	if ((!siz_cuant[0] || siz_cuant[0] < ft_strlen(variable)) && siz_cuant[1])
		siz_cuant[0] = siz_cuant[1];
	res = writer(siz_cuant, comm, variable);
	return (res);
}
