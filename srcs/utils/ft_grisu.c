/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:52:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 17:49:15 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"
#define TEN7  10000000

void	ft_cut(t_myfloat m_prod, unsigned int *ps)
{
	unsigned long int tmp;

	ps[2] = (m_prod.mantissa % (TEN7 >> m_prod.exponent)) << m_prod.exponent;
	tmp = m_prod.mantissa / (TEN7 >> m_prod.exponent);
	ps[1] = tmp % TEN7;
	ps[0] = tmp / TEN7;
}

void	grisu(double *d)
{
	t_myfloat		w;
	unsigned int	ps[3];
	t_myfloat		m_prod;
	int				alpha;
	int				k;

	alpha = 0;
	w = ft_dtomyd(*((unsigned long *)d));
	k = ft_choose_power(w.exponent + 64, alpha);
	m_prod = ft_multiply(w, ft_take_power(k));
	ft_cut(m_prod, ps);
}
