/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilidld_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/04 09:19:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	writer(int *siz_cuant, char *comm, char *variab, char **res)
{
	char	*tmp;
	int		len_com;

	tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0]);
	if (ft_strchr(comm, '-'))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	ft_strdel(&variab);
	len_com = ft_strlen(tmp);
	*res = ft_strjoinfree(*res, tmp);
	return (len_com);
}

static void	*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;
	int		neg;

	neg = 0;
	if (!zero_cuant)
		return (variable);
	new_variab = ft_strnew(ft_strlen(variable) + zero_cuant);
	if (*variable == '-')
	{
		neg = 1;
		*new_variab = '-';
	}
	ft_memset(new_variab + neg, '0', zero_cuant);
	ft_strcat(new_variab, variable + neg);
	ft_strdel(&variable);
	return (new_variab);
}

static void	ajust_cuant_size(int *siz_cuant, char *variable)
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

int			ft_ilidld_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (ft_strchr(comm, 'D'))
		variable = mod_selector[2](ap, ap2, comm);
	else
		variable = mod_selector[ft_mods(comm)](ap, ap2, comm);
	variable = ft_apostrophe_format(comm, variable);
	ajust_cuant_size(siz_cuant, variable);
	if (ft_zero_format(comm))
		variable = write_zeros(variable, siz_cuant[0] - ft_strlen(variable));
	else
		variable = write_zeros(variable, siz_cuant[1]);
	variable = ft_space_format(comm, variable, siz_cuant);
	variable = ft_plus_format(comm, variable, siz_cuant);
	return (writer(siz_cuant, comm, variable, res));
}
