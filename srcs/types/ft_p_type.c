/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 13:00:20 by jagarcia         ###   ########.fr       */
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
	ft_strdel(&variab);
	return (tmp);
}

static void	*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;

	if (!zero_cuant)
		return (variable);
	if (!(new_variab = ft_strnew(ft_strlen(variable) + zero_cuant)))
		return (NULL);
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

int		ft_p_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap[0], ap[1]);
	if (!(variable = (char *)ft_locate_pointer(comm, ap[0], ap[1])))
		return (-1);
	if (!(variable = ft_dectohex(&variable, sizeof(void *))))
		return (-1);
	if (!(variable = ft_hash_format("#x", variable, siz_cuant)))
		return (-1);
	ajust_cuant_size(siz_cuant, variable);
	if (!(variable = write_zeros(variable, ft_zero_format(comm) ? siz_cuant[0]
					- ft_strlen(variable) : siz_cuant[1])))
		return (-1);
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_strnjoinfree(*res, variable, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}
