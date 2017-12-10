/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/10 03:57:25 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, int minus, char *variab, char *modif)
{
	char	*tmp;

	tmp = modif;
	ft_memset(modif, ' ', siz_cuant[0]);
	if (minus)
		ft_strncpy(modif, variab, siz_cuant[1]);
	else
		ft_strncpy(modif + siz_cuant[0] - siz_cuant[1],
				variab, siz_cuant[1]);
	return (tmp);
}

int				ft_s_func(void **fin, char *comm, va_list ap)
{
	int		minus;
	int		siz_cuant[2];
	char	*variab;

	minus = 0;
	variab = va_arg(ap, char *);
	siz_cuant[1] = ft_strlen(variab);
	if (*comm == '-')
	{
		comm++;
		minus = 1;
	}
	if ((siz_cuant[0] = siz_cuant[1]) < ft_atoi(comm))
		siz_cuant[0] = ft_atoi(comm);
	while (ft_isdigit(*comm))
		comm++;
	if (*comm == '.')
	{
		comm++;
		siz_cuant[1] = ft_atoi(comm);
	}
	while (ft_isdigit(ft_atoi(comm)))
		comm++;
//	if (*comm == 'l' || *comm == 'S')
//		variab = (wchar_t *)variab;
	*fin = writer(siz_cuant, minus, variab, ft_strnew(siz_cuant[0] + 1));
	return (sizeof(char) * siz_cuant[0]);
}
