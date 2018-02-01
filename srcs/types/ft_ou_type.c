/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ou_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/31 22:56:16 by jagarcia         ###   ########.fr       */
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
	ft_strdel(&variab);
	return (tmp);
}

static void	*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;

	if (!zero_cuant)
		return (variable);
	new_variab = ft_strnew(ft_strlen(variable) + zero_cuant);
	ft_memset(new_variab, '0', zero_cuant);
	ft_strcat(new_variab, variable);
	ft_strdel(&variable);
	return (new_variab);
}

static void ajust_cuant_size(int *siz_cuant, char *variable)
{
    int len;

	if (!siz_cuant[1] && *variable == '0')
		*variable = '\0';
    len = ft_strlen(variable);
    if (siz_cuant[1] <= len || siz_cuant[1] < 0)
        siz_cuant[1] = 0;
    else
        siz_cuant[1] -= (len);
    if (siz_cuant[0] < len + siz_cuant[1])
        siz_cuant[0] = len + siz_cuant[1];
}

char		*ft_ou_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

	ft_field_format(siz_cuant, comm, ap, ap2);
	variable = (*mod_selector[ft_mods(comm)])(ap, ap2, comm);
	variable = ft_apostrophe_format(comm, variable);
	ajust_cuant_size(siz_cuant, variable);
	if (ft_zero_format(comm))
		variable = write_zeros(variable, siz_cuant[0] - ft_strlen(variable));
	else
		variable = write_zeros(variable, siz_cuant[1]);
	variable = ft_hash_format(comm, variable, siz_cuant);
	res = writer(siz_cuant, ft_minus_format(comm), variable);
	return (res);
}
