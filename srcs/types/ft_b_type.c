/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/21 20:36:06 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (!tmp)
		return (NULL);
	if (ft_minus_format(comm))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	ft_strdel(&variab);
	ft_strdel(&comm);
	return (tmp);
}

int	ft_b_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, &comm, ap);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	variable = (*g_mod_selector[ft_mods(comm)])(ap[0], ap[1], comm);
	if (!variable)
		return (-1);
	ft_ajust_params(siz_cuant, variable, comm);
	variable = ft_zero_format(comm, variable, siz_cuant);
	if (!variable)
		return (-1);
	variable = ft_hash_format(comm, variable, siz_cuant);
	if (!variable)
		return (-1);
	variable = writer(siz_cuant, comm, variable);
	if (!variable)
		return (-1);
	*res = ft_memjoinfree(*res, variable, len, siz_cuant[0]);
	if (!(*res))
		return (-1);
	return (len + siz_cuant[0]);
}
