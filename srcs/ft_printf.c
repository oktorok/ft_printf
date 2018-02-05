/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 06:24:27 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*search_command(char *str)
{
	while (*str != '%' && *str != '{' && *str)
		str++;
	return (str);
}

static unsigned int	find_end(char *str)
{
	unsigned int	pos;
	unsigned int	end;

	pos = 0;
	end = 1;
	while (str[end] != g_types[pos])
	{
		pos++;
		if (!g_types[pos])
		{
			pos = 0;
			end++;
		}
	}
//	*str += (end + 1);
	return (end);
}

static int			exec_command(char *str, va_list ap,
		va_list ap2, char **res)
{
	char			*command;
	int				aux;
	char			n;

	n = 0;
	if (!*str)
		return (ft_strlen(*res));
	aux = find_end(str);
	if (!(command = ft_strsub(str, 1, aux)))
		return (-1);
	while ((str[aux] != g_types[n]) && (n < 27))
		n++;
	if (n == 27)
		return (0);
	aux = (*type_function[n])(command, ap, ap2, res);
	ft_strdel(&command);
	return (aux);
}

int					ft_printf_body(va_list ap, va_list ap2,
		const char *str, char **res)
{
	char	*aux_str;
	char	*head;
	int		len;
	int		aux_len;
	char	*aux_res;

	head = (char *)str;
	len = 0;
	while (1)
	{
		aux_str = search_command(head);
		if (!(aux_res = ft_strsub(head, 0, (int)((aux_str - head) < 0 ?
							ft_strlen(head) : aux_str - head))))
			return (-1);
		if ((aux_len = exec_command(aux_str, ap, ap2, &aux_res)) == -1)
			return (aux_len);
		if(!(*res = ft_memmove(ft_strnew(len + aux_len), *res, len)))
			return (-1);
		ft_memmove((*res) + len, aux_res, aux_len);
		len += aux_len;
		head = aux_str + find_end(aux_str) + 1;
		if (!*aux_str)
			break ;
	}
	return (len);
}

int				ft_printf(const char *str, ...)
{
	char		*res;
	va_list		ap;
	va_list		ap2;
	int			len;

	len = 0;
	va_start(ap, str);
	va_copy(ap2, ap);
	res = NULL;
	len = ft_printf_body(ap, ap2, str, &res);
	write(1, res, len);
	va_end(ap);
	va_end(ap2);
	ft_strdel(&res);
	return (len);
}
