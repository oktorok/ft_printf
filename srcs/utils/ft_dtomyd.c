/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtomyd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 01:24:44 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 17:40:12 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

t_myfloat	ft_dtomyd(unsigned long int d)
{
	t_myfloat	n;

	n.mantissa = ((d << 11) | 0x8000000000000000) >> 11;
	n.exponent = ((d << 1) >> 53) - 1075;
	return (n);
}
