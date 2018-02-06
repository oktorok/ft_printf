/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 03:43:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	writer(int *siz_cuant, char *comm, char *variab, char **res)
{
	char	*tmp;
	int		len_com;

	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (-1);
	if (ft_strchr(comm, '-'))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	ft_strdel(&variab);
	if (!(*res = ft_strjoinfree(*res, tmp)))
		return (-1);
	len_com = ft_strlen(*res);
	return (len_com);
}

static void	*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;
	int		neg;

	if (!zero_cuant)
		return (variable);
	neg = 0;
	if (!(new_variab = ft_strnew(ft_strlen(variable) + zero_cuant)))
		return (NULL);
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

static void	ajust_cuant_size(int *siz_cuant, char *variable)
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

int			ft_b_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (!(variable = (*mod_selector[ft_mods(comm)])(ap, ap2, comm)))
		return (-1);
	ajust_cuant_size(siz_cuant, variable);
	if (!(variable = write_zeros(variable, ft_zero_format ? siz_cuant[0] -
					ft_strlen(variable) : siz_cuant[1])))
		return (-1);
	if (!(variable = ft_hash_format(comm, variable, siz_cuant)))
		return (-1);
	return (writer(siz_cuant, comm, variable, res));
}
