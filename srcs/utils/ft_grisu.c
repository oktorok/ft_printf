/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:52:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 19:16:12 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"
#define TEN7  10000000
#include<stdio.h>
void	ft_cut(t_myfloat m_prod, unsigned int *ps)
{
	unsigned long int tmp;

	ps[2] = (m_prod.mantissa % (TEN7 >> m_prod.exponent)) << m_prod.exponent;
	tmp = m_prod.mantissa / (TEN7 >> m_prod.exponent);
	ps[1] = tmp % TEN7;
	ps[0] = tmp / TEN7;
}

char	*concatenate(char *str, int n)
{
	char *tmp;

	if (!(tmp = ft_itoa))
}

void	grisu(double *d)
{
	t_myfloat		w;
	unsigned int	ps[3];
	t_myfloat		m_prod;
	char			*str;
	int				k;

	w = ft_dtomyd(*((unsigned long *)d));
	k = ft_choose_power(w.exponent + 64, 0);
	m_prod = ft_multiply(w, ft_take_power(k));
	ft_cut(m_prod, ps);
	str = ft_strnew(0);
	str = ft_strjoinfree(str, ft_itoa(ps[0]));
	str = ft_strjoinfree(str, ft_itoa(ps[1]));
//	printf("Num: %s\n",ft_strjoin(ft_strjoin(), ft_itoa(ps[1])), ft_itoa(ps[2])));
}
