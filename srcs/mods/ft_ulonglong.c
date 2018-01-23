/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 00:17:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 19:09:52 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_ulonglong(va_list ap, va_list ap2, char *comm)
{
	return((void *)ft_ulltoa(*((unsigned long long *)ft_locate_date(comm,
						sizeof(unsigned long long), ap, ap2))));
}
