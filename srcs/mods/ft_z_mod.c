/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/30 11:07:22 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_z_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;

	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i'))
		return (ft_ltoa_base(*((size_t *)ft_locate_date(comm,
							14, ap, ap2)), 10));
	if (comand == 'u')
		return (ft_ultoa_base(*((size_t *)ft_locate_date(comm,
							14, ap, ap2)), 10));
	if (comand == 'o')
		return (ft_dectooct(ft_locate_date(comm, 14, ap, ap2),
					sizeof(size_t)));
	if ((comand == 'x') || (comand == 'X'))
		return (ft_dectohex(ft_locate_date(comm, 14, ap, ap2),
					sizeof(size_t)));
	if (comand == 'b')
		return (ft_dectobin(ft_locate_date(comm, 14, ap, ap2),
					sizeof(size_t)));
	return (NULL);
}
