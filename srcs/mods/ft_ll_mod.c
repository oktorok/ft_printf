/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/30 11:05:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ll_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;
	
	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i'))
		return (ft_ltoa_base(*((long long *)ft_locate_date(comm,
							10, ap, ap2)), 10));
	if (comand == 'u')
		return (ft_ultoa_base(*((unsigned long long *)ft_locate_date(comm,
							11, ap, ap2)), 10));
	if (comand == 'o')
		return (ft_dectooct(ft_locate_date(comm, 11, ap, ap2),
					sizeof(unsigned long long)));
	if ((comand == 'x') || (comand == 'X'))
		return (ft_dectohex(ft_locate_date(comm, 11, ap, ap2),
					sizeof(unsigned long long)));
	if (comand == 'b')
		return (ft_dectobin(ft_locate_date(comm, 11, ap, ap2),
					sizeof(unsigned long long)));
	return (NULL);
}