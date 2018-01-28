/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:31:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/28 21:39:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_myfloat	ft_take_power(int k)
{
	t_myfloat	res;
	int			index;

	index = 343 + k;
	res.mantissa = powers_ten[index];
	res.exponent = powers_ten_e[index];
	return (res);
}
