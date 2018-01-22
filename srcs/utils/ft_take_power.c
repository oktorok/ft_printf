/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:31:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 03:42:20 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"
#include <stdio.h>
t_myfloat	ft_take_power(int k)
{
	t_myfloat	res;
	int index = 343 + k;
	res.mantissa = powers_ten[index];
	printf ("El exponente de 10 es: %lu\n",res.mantissa);
	res.exponent = powers_ten_e[index] ;
	printf ("El exponente de 10 es: %i\n",res.exponent);
	return res;
}
