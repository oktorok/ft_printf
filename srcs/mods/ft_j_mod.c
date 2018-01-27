/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_j_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/26 23:24:19 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_j_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;

	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i'))
		return (ft_ltoa_base(*((long *)ft_locate_date(comm,
							sizeof(intmax_t), ap, ap2)), 10));
	if (comand == 'u')
		return (ft_ultoa_base(*((unsigned long *)ft_locate_date(comm,
							sizeof(uintmax_t), ap, ap2)), 10));
	if (comand == 'o')
		return (ft_dectooct(ft_locate_date(comm,
							sizeof(uintmax_t), ap, ap2), sizeof(uintmax_t)));
	if ((comand == 'x') || (comand == 'X'))
		return (ft_dectohex(ft_locate_date(comm,
							sizeof(uintmax_t), ap, ap2), sizeof(uintmax_t)));
	if (comand == 'n')
		return (NULL);
	return (NULL);
}
