/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:12:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 07:54:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*write_zeros(char *variable, int zero_cuant)
{
	char    *new_variab;
    int     neg;

    neg = 0;
    if (!zero_cuant)
        return (variable);
    if (!(new_variab = ft_strnew(ft_strlen(variable) + zero_cuant)))
        return (NULL);
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

char		*ft_zero_format(char *comm, char *variable, int *siz_cuant)
{
	if (siz_cuant[1] == -1)
	{
		siz_cuant[1] = 0;
		if (ft_search_zero_format(comm))
		{
			return (write_zeros(variable, siz_cuant[0] - ft_strlen(variable)));
		}
	}
	return (write_zeros(variable, siz_cuant[1]));
}
