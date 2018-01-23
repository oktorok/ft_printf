/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:03:38 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 19:17:08 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_signed_char(va_list ap, va_list ap2, char *comm)
{
	return ((void *)ft_itoa(*((signed char *)ft_locate_date(comm,
						sizeof(signed char), ap, ap2))));
}
