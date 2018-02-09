/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/09 07:27:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;
	int		len_com;

	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (NULL);
	if (ft_strchr(comm, '-'))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	ft_strdel(&variab);
	return (tmp);
}

void		ajust_cuant_size(char *variable, int *siz_cuant)
{
	if (!siz_cuant[0])
		siz_cuant[0] = 10;
	if (siz_cuant[1] < 0)
		siz_cuant[1] = 6;
}

int			ft_f_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (!(variable = mod_selector[ft_mods(comm)](ap[0], ap[1], comm)))
		return (-1);
	ajust_cuant_size(variable, siz_cuant);
	if (!(variable = ft_round(variable, siz_cuant[1])))
		return (-1);
	if (!(variable = ft_point(variable)))
		return (-1);
	if (!(variable = ft_apostrophe_format(comm, variable)))
		return (-1);
	if (!(variable = ft_zero_format(comm, variable, siz_cuant)))
		return (-1);
	if (!(variable = ft_space_format(comm, variable, siz_cuant)))
		return (-1);
	if (!(variable = ft_plus_format(comm, variable, siz_cuant)))
		return (-1);
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
