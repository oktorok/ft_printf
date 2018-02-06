/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 04:44:42 by jagarcia         ###   ########.fr       */
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
	return (end);
}

static int			exec_command(char *str, va_list *ap, size_t len, char **res)
{
	char			*command;
	int				aux;
	char			n;

	n = 0;
	if (!*str)
		return (len);
	aux = find_end(str);
	if (!(command = ft_strsub(str, 1, aux)))
		return (-1);
	while ((str[aux] != g_types[n]) && (n < 27))
		n++;
	if (n == 18)
	{
		ft_n_type(command, ap[0], ap[1], len);
		return (len);
	}
	if (n == 27)
		return (0);
	aux = (*type_function[n])(command, ap[0], ap[1], res);
	ft_strdel(&command);
	return (aux);
}

int					ft_printf_body(va_list *ap, const char *str, char **res)
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
		aux_len = (int)((aux_str - head) < 0 ? ft_strlen(head) : aux_str -
				head);
		aux_res = ft_memmove(ft_strnew(len + aux_len), *res, len);
		ft_memmove(aux_res + len, ft_strsub(head, 0, aux_len), aux_len);
		if ((len = exec_command(aux_str, ap, len + aux_len, &aux_res)) == -1)
			return (-1);
		else if (len == ft_strlen(*res))
			len += aux_len;
		*res = aux_res;
		head = aux_str + find_end(aux_str) + 1;
		if (!*aux_str)
			break ;
	}
	return (len);
}

int				ft_printf(const char *str, ...)
{
	char		*res;
	va_list		ap[2];
	int			len;

	len = 0;
	va_start(ap[0], str);
	va_copy(ap[1], ap[0]);
	res = NULL;
	len = ft_printf_body(ap, str, &res);
	write(1, res, len);
	va_end(ap[0]);
	va_end(ap[1]);
	ft_strdel(&res);
	return (len);
}
