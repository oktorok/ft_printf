/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/13 02:47:30 by jagarcia         ###   ########.fr       */
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

static char		*wcharlector(char *variab)
{
	wchar_t *aux;
	char *res;
	aux = (wchar_t *)variab;
	res = (char *)malloc(sizeof(wchar_t) * ft_wstrlen(aux));
	res = ft_strcat(res, ft_utf_8(*aux));
	aux++;
	while (*aux)
	{
		res = ft_strcat(res, ft_utf_8(*aux));
		aux++;
	}
	return (res);
}


int				ft_s_func(void **fin, char *comm, va_list ap)
{
	int		minus;
	int		siz_cuant[2];
	char	*variab;

	minus = 0;
	siz_cuant[0] = 0;
	variab = va_arg(ap, char *);
	if (*comm == '-')
	{
		comm++;
		minus = 1;
	}
	siz_cuant[1] = ft_strlen(variab);
	ft_field_func(siz_cuant, &comm);
	if (*comm == 'l' || *comm == 'S')
	{
		siz_cuant[1] = ft_wstrlen((wchar_t *)variab) * sizeof(wchar_t);
		if (siz_cuant[0] < siz_cuant[1])
			siz_cuant[0] = siz_cuant[1];
		*fin = writer(siz_cuant, minus, wcharlector(variab), ft_strnew(siz_cuant[0] + 1));
	}
	else
		*fin = writer(siz_cuant, minus, variab, ft_strnew(siz_cuant[0] + 1));
	return (sizeof(char) * siz_cuant[0]);
}
