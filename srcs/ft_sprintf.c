/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 04:48:06 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/31 05:44:21 by mrodrigu         ###   ########.fr       */
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
	while (((*(*str - 1)) != g_types[n]) && (n < 26))
		n++;
	if (n == 26)
		return (NULL);
	if (command[ft_strlen(command) - 1] == 'n')
		return (ft_n_type(command, ap, ap2, str2));
	res = (*type_function[n])(command, ap, ap2);
	ft_strdel(&command);
	return (res);
}

static int				finish_printf(char *res, va_list ap, va_list ap2, char *buf)
{
	ft_strcpy(buf, res);
	va_end(ap);
	va_end(ap2);
	return (ft_strlen_free(res));
}

int						ft_sprintf(char *buf, const char *str, ...)
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
		aux_str = search_command((char *)head_str);
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
	return (finish_printf(res, ap, ap2, buf));
}
