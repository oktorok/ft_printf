/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/04 02:14:26 by jagarcia         ###   ########.fr       */
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
		va_list ap2, char *res)
{
	char			*command;
	char			*com_res;
	char			n;

	if (!(**str))
		return (NULL);
	n = 0;
	command = ft_strsub(*str, 1, find_end(str));
	while (((*(*str - 1)) != g_types[n]) && (n < 27))
		n++;
	if (n == 27)
		return (NULL);
	if (command[ft_strlen(command) - 1] == 'n')
		return (ft_n_type(command, ap, ap2, res));
	com_res = (*type_function[n])(command, ap, ap2);
	ft_strdel(&command);
	return (com_res);
}

static size_t			finish_printf(char *res, va_list ap, va_list ap2, int len)
{
	write(1, res, len);
	va_end(ap);
	va_end(ap2);
	ft_strdel(&res);
	return (len);
}

int						ft_printf(const char *str, ...)
{
	char		*res;
	char		*head;
	char		*aux_str;
	int			len;
	va_list		ap;
	va_list		ap2;

	len = 0;
	va_start(ap, str);
	va_copy(ap2, ap);
	head = (char *)str;
	if (!(res = ft_strnew(0)))
		return (-1);
	while (1)
	{
		aux_str = search_command(head);
//		aux_str = ft_strchr(head, '%');
		len += ft_realloc_printf(&res, ft_strsub(head, 0, (int)((aux_str -
							head) < 0 ? ft_strlen(head) : aux_str - head)),
				exec_command(&aux_str, ap, ap2, res));
		head = aux_str;
		if (!*head)
			break ;
	}
	return (finish_printf(res, ap, ap2, len));
/*	while (1)
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
	}*/
//	return (finish_printf(res, ap, ap2));
}
