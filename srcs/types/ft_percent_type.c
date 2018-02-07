/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 07:12:47 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;
	int		len_com;
	if (ft_search_zero_format(comm))
	{
		if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), '0', siz_cuant[0])))
			return (NULL);
	}
	else
		if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
			return (NULL);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, 1);
	else
		ft_strncpy(tmp + siz_cuant[0] - 1, variab, 1);
	ft_strdel(&variab);
	return (tmp);
}

int			ft_percent_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	if (!(variable = ft_strnew(1)))
		return (-1);
	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	*variable = '%';
	ft_ajust_params(comm, siz_cuant, variable);
	if (!(variable = ft_zero_format(variable, siz_cuant[0])))
		return (-1);
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
