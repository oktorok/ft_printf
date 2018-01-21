/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:31:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/21 21:10:46 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

t_myfloat	ft_take_power(int k)
{
	double	d;
	void	*p;

	d = g_ten_powers[k];
	p = &d;
	return (ft_dtomyd(*((unsigned long int *)p)));
}
