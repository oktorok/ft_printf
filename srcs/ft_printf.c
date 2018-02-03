/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/03 03:13:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char				*search_command(char *str)
{
	while (*str != '%' && *str != '{' && *str)
		str++;
	return (str);
}

static unsigned int		find_end(char **str)
{
	unsigned int	pos;
	unsigned int	end;

	pos = 0;
	end = 1;
	while ((*str)[end] != g_types[pos])
	{
		pos++;
		if (!g_types[pos])
		{
			pos = 0;
			end++;
		}
	}
	*str += (end + 1);
	return (end);
}

static char				*exec_command(char **str, va_list ap,
		va_list ap2, char *str2)
{
	char			*command;
	char			*res;
	char			n;

	n = 0;
	command = ft_strsub(*str, 1, find_end(str));
	while (((*(*str - 1)) != g_types[n]) && (n < 27))
		n++;
	if (n == 27)
		return (NULL);
	if (command[ft_strlen(command) - 1] == 'n')
		return (ft_n_type(command, ap, ap2, str2));
	res = (*type_function[n])(command, ap, ap2);
	ft_strdel(&command);
	return (res);
}

static size_t			finish_printf(char *res, va_list ap, va_list ap2)
{
	int len;

	len = ft_strlen(res);
	ft_putstr(res);
	va_end(ap);
	va_end(ap2);
	ft_strdel(&res);
	return (len);
}

int						ft_printf(const char *str, ...)
{
	char		*res;
	char		*head_str;
	char		*aux_str;
	va_list		ap;
	va_list		ap2;

	va_start(ap, str);
	va_copy(ap2, ap);
	head_str = (char *)str;
	if (!(res = ft_strnew(0)))
		return (-1);
	while (1)
	{
		aux_str = search_command(head_str);
		if (!(res = ft_realloc_printf(res, head_str, aux_str)))
			return (-1);
		if (*aux_str)
			if (!(res = ft_realloc_printf(res,
							exec_command(&aux_str, ap, ap2, res), NULL)))
				return (-1);
		head_str = aux_str;
		if (!(*aux_str))
			break ;
	}
	return (finish_printf(res, ap, ap2));
}
