/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulloctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 00:17:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/23 03:41:26 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_ulloctal(va_list ap, va_list ap2, char *comm)
{
	return((void *)ft_ulltoa_base(*((unsigned long *)ft_locate_date(comm,
						sizeof(unsigned long long), ap, ap2)), 8));
}
