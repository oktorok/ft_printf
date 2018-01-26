/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/25 21:59:54 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ll_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;
	
	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i'))
		return (ft_ltoa_base(*((long *)ft_locate_date(comm,
							sizeof(long), ap, ap2)), 10));
	if (comand == 'u')
		return (ft_ultoa_base(*((unsigned long *)ft_locate_date(comm,
							sizeof(unsigned long), ap, ap2)), 10));
	if (comand == 'o')
		return (ft_ultoa_base(*((unsigned long *)ft_locate_date(comm,
							sizeof(unsigned long), ap, ap2)), 8));
	if ((comand == 'x') || (comand == 'X'))
		return (ft_ultoa_base(*((unsigned long *)ft_locate_date(comm,
							sizeof(unsigned long), ap, ap2)), 16));
	if (comand == 'n')
		return (NULL);
	return (NULL);
}
