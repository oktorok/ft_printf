/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sls_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/07 23:25:39 by jagarcia         ###   ########.fr       */
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
	if (ft_mods(comm) == 4 || ft_strchr(comm, 'S'))
		ft_strdel(&variab);
	ft_strdel(&comm);
	return (tmp);
}

int	ft_sls_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, &comm, ap);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (ft_mods(comm) == 4 || ft_strchr(comm, 'S'))
	{
		variable = ft_wchar(ap, ap+1, siz_cuant, comm);
		if (!variable)
			return (-1);
	}
	else
		variable = (char *)ft_locate_pointer(comm, ap, ap+1);
	if (comm[ft_strlen(comm) - 1] == 's' && !variable)
		variable = "(null)";
	ft_ajust_params(siz_cuant, variable, comm);
	variable = writer(siz_cuant, comm, variable);
	if (!variable)
		return (-1);
	*res = ft_memjoinfree(*res, variable, len, siz_cuant[0]);
	if (!*res)
		return (-1);
	return (len + siz_cuant[0]);
}
