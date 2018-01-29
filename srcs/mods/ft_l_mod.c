/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/29 22:29:38 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_l_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;
	
	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i') || (comand == 'D'))
		return (ft_ltoa_base(*((long *)ft_locate_date(comm,
							12, ap, ap2)), 10));
	if ((comand == 'u') || (comand == 'U'))
		return (ft_ultoa_base(*((unsigned long *)ft_locate_date(comm,
							9, ap, ap2)), 10));
	if ((comand == 'o') || (comand == 'O'))
		return (ft_dectooct(ft_locate_date(comm, 9, ap, ap2),
				sizeof(unsigned long)));
	if ((comand == 'x') || (comand == 'X'))
		return (ft_dectohex(ft_locate_date(comm, 9, ap, ap2),
					sizeof(unsigned long)));
	if (comand == 'b')
		return (ft_dectobin(ft_locate_date(comm, 9, ap, ap2),
					sizeof(unsigned long)));
	return (NULL);
}
