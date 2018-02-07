/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 06:52:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	tmp = variab;
	if (ft_strchr(comm, 'X'))
		while (*variab)
		{
			*variab = ft_toupper(*variab);
			variab++;
		}
	variab = tmp;
	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (NULL);
	if (ft_strchr(comm, '-'))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	ft_strdel(&variab);
	return (tmp);
}

static void	ajust_cuant_size(char *comm, int *siz_cuant, char *variable)
{
	int len;

	if (!siz_cuant[1] && *variable == '0')
		*variable = '\0';
	len = ft_strlen(variable);
	if (siz_cuant[1] >= 0)
	{
		if (siz_cuant[1] <= len)
			siz_cuant[1] = 0;
		else
			siz_cuant[1] -= len;
		if (siz_cuant[0] < len + siz_cuant[1])
			siz_cuant[0] = len + siz_cuant[1];
	}
	else
	{
		siz_cuant[1] = 0;
		if (siz_cuant[0] < len)
			siz_cuant[0] = len;
		if (ft_search_zero_format(comm))
			siz_cuant[1] = siz_cuant[0] - len;
	}	
}

int			ft_xlx_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;
	size_t	i;

	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (ft_strchr(comm, 'X'))
	{
		if (!(variable = (*mod_selector[2])(ap[0], ap[1], comm)))
			return (-1);
	}
	else
		if (!(variable = (*mod_selector[ft_mods(comm)])(ap[0], ap[1], comm)))
			return (-1);
	ajust_cuant_size(comm, siz_cuant, variable);
	if (!(variable = ft_zero_format(variable, siz_cuant)))
		return (-1);
	i = 0;
	while (variable[i])
		if (variable[i++] != '0')
		{
			if (!(variable = ft_hash_format(comm, variable, siz_cuant)))
				return (-1);
			break ;
		}
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
