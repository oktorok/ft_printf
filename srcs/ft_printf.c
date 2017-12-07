/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/07 01:12:49 by jagarcia         ###   ########.fr       */
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
	return (pos_fmt);
}

static int		istype(char c)
{
	char	types[27] ="sSpdDioOuUxXcCeEfFgGaAnbrk";
	int		i;

	i = 0;
	while (c != types[i])
	{
		if (!types[i])
			return (0);
		i++;
	}
	return (1);
}

static void		read_command(char *format)
{
	int		comm_end;
	char	*command;
	comm_end = 0;
	if (*format == '%')
		while (!istype(format[comm_end]))
			comm_end++;
	command = ft_strsub(format, 1, comm_end + 1);
	ft_putstr(command);
}

int				ft_printf(const char *format, ...)
{
	char	*res;
	int		pos_for;
	int		cant_print;

	cant_print = 0;
	pos_for = search_command((char *)format, &cant_print);
	res = ft_strnew(pos_for);
	ft_strncpy(res, format, pos_for);
	format = format + pos_for;
	read_command((char *)format);
	return (1);
}
