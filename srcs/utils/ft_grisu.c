/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:52:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/21 21:43:46 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"
#include <stdio.h>
#define TEN7  10000000

void	ft_cut(t_myfloat D, unsigned int *ps)
{
	unsigned long int tmp;
	
	ps[2] = (D.mantissa % (TEN7 >> D.exponent)) << D.exponent;
	tmp = D.mantissa / (TEN7 >> D.exponent);
	ps[1] = tmp % TEN7;
	ps[0] = tmp /TEN7;
}

void	grisu(double *d)
{
	t_myfloat 		w;
	unsigned int	ps[3];
	t_myfloat		D;
	int				alpha;
	int				k;

	alpha = 0;
	w = ft_dtomyd(*((unsigned long *)d));
	k = ft_choose_power(w.exponent + 64, alpha);
	printf ("La mantissa vale: %lu\nEl exponente vale: %d\nk vale: %d\n",w.mantissa, w.exponent, k);
	D = ft_multiply(w, ft_take_power(k));
	ft_cut(D, ps);
	printf("%u%07u%07ue%d",ps[0], ps[1], ps[2], -k);
}
