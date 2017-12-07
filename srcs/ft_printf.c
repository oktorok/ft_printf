/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/08 00:32:14 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int		search_command(char *fmt, int *cant_print)
{
	int pos_fmt;

	pos_fmt = 0;
	while (fmt[pos_fmt] != '%' && fmt[pos_fmt] != '{' && fmt[pos_fmt])
	{
		(*cant_print)++;
		pos_fmt++;
	}
	if (fmt[pos_fmt] == '%' || fmt[pos_fmt] == '{')
		return (pos_fmt);
	else
		return (-1);
}

static int		exec_command(char *format)
{
	int		comm_end;
	int		i;
	int		j;

	comm_end = 1;
	j = 0;
	i = 0;
	while (format[comm_end] != g_types[j][i])
	{
		i++;
		if (!g_types[j][i])
		{
			i = 0;
			j++;
		}
		if (j == 14)
		{
			j = 0;
			i = 0;
			comm_end++;
		}
	}
	ft_putchar('<');
	ft_putstr((*type_function[j])(ft_strsub(format, 1, comm_end - 1)));
	ft_putstr(">\n");
	return (comm_end + 1);
}

int				ft_printf(const char *format, ...)
{
	char	*res;
	int		pos_for;
	int		cant_print;

	cant_print = 0;
	res = NULL;
	while ((pos_for = search_command((char *)format, &cant_print)) >= 0)
	{
		if (!(res = ft_realloc_printf(res, ft_strsub(format, 0, pos_for))))
			return (-1);
		format = format + pos_for;
		format = format + exec_command((char *)format);
	}
	if (!(res = ft_realloc_printf(res, (char *)format)))
		return (-1);
	ft_putstr("RES VALE: ");
	ft_putstr(res);

	return (1);
}
