/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 00:17:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 19:08:30 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_ulong(va_list ap, va_list ap2, char *comm)
{
	return((void *)ft_ultoa(*((unsigned long *)ft_locate_date(comm,
						8, ap, ap2))));
}
