/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 00:45:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, int minus, char *variab)
{
	char	*tmp;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (minus)
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	return (tmp);
}

static void	*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;
	int		neg;

	if (!zero_cuant)
		return (variable);
	neg = 0;
	new_variab = ft_strnew(ft_strlen(variable) + zero_cuant);
	if (*variable == '-')
	{
		*new_variab = '-';
		neg = 1;
	}
	ft_memset(new_variab + neg, '0', zero_cuant + neg);
	ft_strcat(new_variab, variable + neg);
	ft_strdel(&variable);
	return (new_variab);
}

char		*ft_id_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;
	size_t	len;

	ft_field_format(siz_cuant, comm, ap, ap2);
	variable = (char *)(*mod_selector[ft_mods(comm)][0])(ap, ap2,
			siz_cuant, comm);
	variable = ft_apostrophe_format(comm, variable);
	len = ft_strlen(variable);
	if (siz_cuant[1] <= len || siz_cuant[1] < 0)
		siz_cuant[1] = 0;
	else
		siz_cuant[1] -= len;
	if (siz_cuant[0] < len + siz_cuant[1])
		siz_cuant[0] = len + siz_cuant[1];
	if (ft_zero_format(comm))
		variable = write_zeros(variable, siz_cuant[0] - len);
	else
		variable = write_zeros(variable, siz_cuant[1]);
	variable = ft_space_format(comm, variable);
	variable = ft_plus_format(comm, variable);
	res = writer(siz_cuant, ft_minus_format(comm), variable);
	return (res);
}