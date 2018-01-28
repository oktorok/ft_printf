/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/28 21:23:57 by jagarcia         ###   ########.fr       */
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

char		*ft_p_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;
	size_t	len;

	ft_field_format(siz_cuant, comm, ap, ap2);
	variable = (char *)ft_locate_pointer(comm, ap, ap2);
	variable = ft_dectohex(&variable, sizeof(void *));
	variable = ft_hash_format("#x", variable, siz_cuant);
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
	res = writer(siz_cuant, ft_minus_format(comm), variable);
	return (res);
}
