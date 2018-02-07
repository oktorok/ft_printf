/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:12:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 06:55:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_zero_format(char *variable, int zero_cuant)
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
