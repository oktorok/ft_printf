/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grisu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:52:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/26 20:27:16 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define TEN7  10000000

static void	ft_cut(t_myfloat m_prod, unsigned int *ps)
{
	unsigned long int	tmp;

	ps[2] = (m_prod.mantissa % (TEN7 >> m_prod.exponent)) << m_prod.exponent;
	tmp = m_prod.mantissa / (TEN7 >> m_prod.exponent);
	ps[1] = tmp % TEN7;
	ps[0] = tmp / TEN7;
}

static char	*ft_concatenate(unsigned int *ps, char *str, int n)
{
	char			*tmp;
	char			*tmp2;
	unsigned int	len;

	tmp = ft_itoa(ps[n]);
	if (!tmp)
		return (NULL);
	len = ft_strlen(tmp);
	if (len < 7)
	{
		tmp2 = ft_strnew(7 - len);
		if (!tmp2)
			return (NULL);
		ft_memset(tmp2, '0', 7 - len);
		return (ft_strjoinfree(str, ft_strjoinfree(tmp2, tmp)));
	}
	return (ft_strjoinfree(str, tmp));
}

static char	*ft_inf_nan(unsigned long d)
{
	char	is_neg;

	if (d & 0x8000000000000000)
		is_neg = 1;
	if ((d << 1) == 0xFFE0000000000000)
	{
		if (is_neg)
			return (ft_strdup("-inf"));
		else
			return (ft_strdup("inf"));
	}
	return (ft_strdup("nan"));
}

static char	*final_steps(unsigned int *ps, char *str, int k)
{
	str = ft_strjoinfree(str, ft_itoa(ps[0]));
	if (!str)
		return (NULL);
	str = ft_concatenate(ps, str, 1);
	if (!str)
		return (NULL);
	str = ft_concatenate(ps, str, 2);
	if (!str)
		return (NULL);
	str = ft_strjoinfree(str,
			ft_strjoinfree(ft_memset(ft_strnew(1), 'e', 1), ft_itoa(-k)));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_grisu(double *d)
{
	t_myfloat		w;
	unsigned int	ps[3];
	t_myfloat		m_prod;
	char			*str;
	int				k;

	if (((*((unsigned long *)d) << 1) & 0xFFE0000000000000)
		== 0xFFE0000000000000)
		return (ft_inf_nan(*((unsigned long *)d)));
	w = ft_dtomyd(*((unsigned long *)d));
	k = ft_choose_power(w.exponent + 64, 0);
	m_prod = ft_multiply(w, ft_take_power(k));
	ft_cut(m_prod, ps);
	if ((*((unsigned long *)(d)) & 0x8000000000000000))
		str = ft_strdup("-");
	else
		str = ft_strnew(0);
	str = final_steps(ps, str, k);
	if (!str)
		return (NULL);
	return (str);
}
