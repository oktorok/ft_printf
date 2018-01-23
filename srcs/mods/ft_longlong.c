/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:03:38 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 19:15:53 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_longlong(va_list ap, va_list ap2, char *comm)
{
	return ((void *)ft_lltoa(*((long long *)ft_locate_date(comm,
						sizeof(long long), ap, ap2))));
}
