/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:03:38 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 19:12:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_int(va_list ap, va_list ap2, char *comm)
{
	return ((void *)ft_itoa(*((int *)ft_locate_date(comm,
						sizeof(int), ap, ap2))));
}
