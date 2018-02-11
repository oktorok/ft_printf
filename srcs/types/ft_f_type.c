/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feleglg_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/11 07:31:16 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (NULL);
	if (ft_strchr(comm, '-'))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
    if (comm[ft_strlen(comm) - 1] == 'E')
        *(ft_strchr(tmp, 'e')) = 'E';
	ft_strdel(&variab);
	return (tmp);
}

void		ajust_cuant_size(char *variab, int *siz_cuant, char *comm)
{
	if (siz_cuant[1] > 0)
		siz_cuant[1]++;
	if (siz_cuant[1] < 0)
	{
		if (ft_toupper(comm[ft_strlen(comm) - 1]) == 'F')
			siz_cuant[1] = 7;
		else 
			siz_cuant[1] = 11;
	}
	if (siz_cuant[0] < 17 - ft_atoi(ft_strchr(variab, 'e') + 2) + siz_cuant[1])
		siz_cuant[0] = 17 - ft_atoi(ft_strchr(variab, 'e') + 2) + siz_cuant[1];
}

int			ft_fele_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_putchar('B');
	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
  		return (-1);
	if (!(variable = mod_selector[ft_mods(comm)](ap[0], ap[1], comm)))
		return (-1);
	ajust_cuant_size(variable, siz_cuant, comm);
	if (!(variable = ft_round(variable, siz_cuant[1])))
		return (-1);
	if (!(variable = ft_putthepoint(variable, siz_cuant)))
		return (-1);
	if (!(variable = ft_apostrophe_format(comm, variable, siz_cuant)))
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
