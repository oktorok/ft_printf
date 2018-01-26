/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:52:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/26 22:29:35 by mrodrigu         ###   ########.fr       */
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

char	*ft_concatenate(unsigned int *ps, char *str, int n)
{
	char			*tmp;
	char			*tmp2;
	unsigned int	len;

	if (!(tmp = ft_itoa(ps[n])))
		return (NULL);
	if ((len = ft_strlen(tmp)) < 7)
	{
		tmp2 = ft_strnew(7 - len);
		ft_memset(tmp2, '0', 7 - len);
		return (ft_strjoinfree(str, ft_strjoinfree(tmp2, tmp)));
	}
	return (ft_strjoinfree(str, tmp));
}

char	*grisu(double *d)
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
	str = ft_concatenate(ps, str, 1);
	str = ft_concatenate(ps, str, 2);
	str = ft_strjoinfree(str, ft_strjoinfree(ft_memset(ft_strnew(1), 'e', 1), ft_itoa(-k)));
	return (str);
}
