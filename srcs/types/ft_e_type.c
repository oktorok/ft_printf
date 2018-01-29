/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 04:38:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/29 08:41:25 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char	*extract_exponent(int e)
{
	char	*exp;

	if (e >=0)
	{
		if (e <= 9)
		{
			exp = ft_strnew(2);
			exp[1] = '0';
		}
		else
			exp = ft_strnew(1);
		exp[0] = '+';
	}
	else if (e >= -9)
	{
		exp = ft_strnew(2);
		exp[0] = '-';
		exp[1] = '0';
		e = -e;
	}
	else
		exp = ft_strnew(0);
	return(ft_strjoinfree(exp, ft_itoa(e)));
}

static char	round_num(char *d, int prec)
{
	char	ac;

	ac = 0;
	while (prec >= 0)
	{
		if (d[prec + 1] >= 53 || ac)
		{
			if (d[prec] != '9')
			{
				d[prec] = d[prec] + 1;
				ac = 0;
				break ;
			}
			else if (!prec && d[prec] == '9')
				d[prec] = '1';
			else
			{
				d[prec] = '0';
				ac = 1;
			}
		}
		else
			break ;
		prec--;
	}
	return (ac);
}

static char	*normalize(char *d, unsigned int prec)
{
	unsigned int	i;
	char			*exp;
	char			*str;

	if (!prec)
		prec = 6;
	i = 0;
	while (d[i] != 'e')
		i++;
	if (!(exp  = extract_exponent(ft_atoi(d + i + 1) + i - 1 + round_num(d, prec))))
		return (NULL);
	d[i] = '\0';
	str = ft_strnew(prec + 3);
	ft_memset(str, '0', prec + 3);
	str[0] = d[0];
	str[1] = '.';
	if (prec < (i - 1))
		ft_memcpy(str + 2, d + 1, prec);
	else
		ft_memcpy(str + 2, d + 1, i - 1);
	ft_strdel(&d);
	str[prec + 2] = 'e';
	if (!(str = ft_strjoinfree(str, exp)))
		return (NULL);
	return (str);
}

char		*ft_e_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, comm, ap, ap2);
	variable = ft_grisu((double *)ft_locate_date(comm, 15, ap, ap2));
	variable = normalize(variable, siz_cuant[1]);
	return (variable);
}
