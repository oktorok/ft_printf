/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:03:38 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 19:13:10 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_intmax(va_list ap, va_list ap2, char *comm)
{
	return ((void *)ft_ltoa(*((intmax_t *)ft_locate_date(comm,
						sizeof(intmax_t), ap, ap2))));
}
