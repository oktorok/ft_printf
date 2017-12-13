/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/13 02:12:41 by jagarcia         ###   ########.fr       */
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

static int		exec_command(char *format, t_list **res_tmp, va_list ap)
{
	int		comm_end;
	int		i;
	int		j;
	void	*formated;

	formated = NULL;
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
	i = (*type_function[j])(&formated, ft_strsub(format, 1, comm_end), ap);
	*res_tmp = ft_realloc_printf(res_tmp, formated, i);
	return (comm_end + 1);
}

void static		writer(t_list *final)
{
	while (final)
	{
		ft_putbytes(final->content, final->content_size);
		final = final->next;
	}
	return;
}

int				ft_printf(const char *format, ...)
{
	t_list		*res;
	t_list		*tmp;
	int			pos_for;
	int			cant_print;
	va_list		ap;

	va_start(ap, format);
	cant_print = 0;
	res = NULL;
	while ((pos_for = search_command((char *)format, &cant_print)) >= 0)
	{
		if (!(tmp = ft_realloc_printf(&res, ft_strsub(format, 0, pos_for), pos_for)))
			return (-1);
		format = format + pos_for;
		format = format + exec_command((char *)format, &tmp, ap);
	}
	if (*format)
		if (!(tmp = ft_realloc_printf(&tmp, (char *)format, ft_strlen((char *)format))))
			return (-1);
	writer(res);
	va_end(ap);
	return (1);
}
