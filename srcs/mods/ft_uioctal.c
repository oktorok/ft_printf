/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uioctal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 00:17:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/23 03:39:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_uioctal(va_list ap, va_list ap2, char *comm)
{
	return((void *)ft_uitoa_base(*((unsigned int *)ft_locate_date(comm,
						sizeof(unsigned int), ap, ap2)), 8));
}
