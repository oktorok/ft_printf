/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/04 09:28:23 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	writer(int *siz_cuant, char *comm, char *variab, char **res)
{
	char	*tmp;
	int		len_com;

	if (ft_zero_format(comm))
		tmp = ft_memset(ft_strnew(siz_cuant[0]), '0', siz_cuant[0]);
	else
		tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (ft_strchr(comm, '-'))
		tmp = ft_strncpy(tmp, variab, 1);
	else
		ft_strncpy(tmp + siz_cuant[0] - 1, variab, 1);
	ft_strdel(&variab);
	len_com = ft_strlen(tmp);
	*res = ft_strjoinfree(*res, tmp);
	return (len_com);
}

int			ft_percent_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;

	variable = ft_strnew(1);
	ft_field_format(siz_cuant, comm, ap, ap2);
	*variable = '%';
	if (siz_cuant[0] < 1)
		siz_cuant[0] = 1;
	return (writer(siz_cuant, comm, variable, res));
}
