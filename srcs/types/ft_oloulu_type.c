/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oloulu_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 02:22:32 by jagarcia         ###   ########.fr       */
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
	*res = ft_strjoinfree(*res, tmp);
	len_com = ft_strlen(*res);
	return (len_com);
}

static void	*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;

	if (!zero_cuant)
		return (variable);
	if (!(new_variab = ft_strnew(ft_strlen(variable) + zero_cuant)))
		return (-1);
	ft_memset(new_variab, '0', zero_cuant);
	ft_strcat(new_variab, variable);
	ft_strdel(&variable);
	return (new_variab);
}

static void	ajust_cuant_size(int *siz_cuant, char *variable)
{
	int		len;

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

int			ft_oloulu_type(char *comm, va_list ap, va_list ap2, char **res)
{
	int		siz_cuant[2];
	char	*variable;
	size_t	len;

	ft_field_format(siz_cuant, comm, ap, ap2);
	if (!(siz_cuant[0] == -2 || siz_cuant[1] == -2))
		return (-1);
	if (ft_strchr(comm, 'O') || ft_strchr(comm, 'U'))
	{
		if (!(variable = (*mod_selector[2])(ap, ap2, comm)))
			return (-1);
	}
	else
		if (!(variable = (*mod_selector[ft_mods(comm)])(ap, ap2, comm)))
			return (-1);
	if (!(variable = ft_apostrophe_format(comm, variable)))
		return (-1);
	ajust_cuant_size(siz_cuant, variable);
	if (!(variable = write_zeros(variable, ft_zero_format(comm) ? siz_cuant[0]
					- ft_strlen(variable) : siz_cuant[1])))
		return (-1);
	len = 0;
	while (variable[len++] != '0')
	{
		if (!(variable = ft_hash_format(comm, variable, siz_cuant)))
			return (-1);
		break ;
	}
	return (writer(siz_cuant, comm, variable, res));
}
