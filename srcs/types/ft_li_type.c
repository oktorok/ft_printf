/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_li_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 22:11:41 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (ft_strchr(comm, '-'))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	ft_strdel(&variab);
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

static void ajust_cuant_size(int *siz_cuant, char *variable)
{
    int neg;
    int len;

    neg = 0;
    if (*variable == '-')
        neg = 1;
	if (!siz_cuant[1] && *variable == '0')
		*variable = '\0';
    len = ft_strlen(variable);
    if (siz_cuant[1] <= len - neg || siz_cuant[1] < 0)
        siz_cuant[1] = 0;
    else
        siz_cuant[1] -= (len - neg);
    if (siz_cuant[0] < len + siz_cuant[1])
        siz_cuant[0] = len + siz_cuant[1];
}

char		*ft_li_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

	ft_field_format(siz_cuant, comm, ap, ap2);
		variable = ft_ltoa_base(*((long *)ft_locate_date(comm, 12, ap, ap2)), 10);
	variable = ft_apostrophe_format(comm, variable);
	ajust_cuant_size(siz_cuant, variable);
	if (ft_zero_format(comm))
		variable = write_zeros(variable, siz_cuant[0] - ft_strlen(variable));
	else
		variable = write_zeros(variable, siz_cuant[1]);
	variable = ft_space_format(comm, variable, siz_cuant);
	variable = ft_plus_format(comm, variable, siz_cuant);
	res = writer(siz_cuant, comm, variable);
	return (res);
}
