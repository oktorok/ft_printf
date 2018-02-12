/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 04:48:06 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/12 18:06:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*search_command(char *str)
{
	while (*str != '%' && *str != '{' && *str)
		str++;
	return (str);
}

static int		find_end(char *str)
{
	unsigned int	pos;
	unsigned int	end;

	pos = 0;
	end = 1;
	while (str[end] != g_types[pos] && str[end])
	{
		pos++;
		if (!g_types[pos])
		{
			pos = 0;
			end++;
		}
	}
	if (!str[end])
		return (0);
	return (end);
}

static int		exec_command(char *str, va_list *ap, size_t len, char **res)
{
	char			*command;
	int				aux;
	int				n;

	n = 0;
	if (!*str)
		return (len);
	if ((aux = find_end(str)) < 0)
		return (len);
	if (!(command = ft_strsub(str, 1, aux)))
		return (-1);
	if (!*command)
		return (len);
	while ((str[aux] != g_types[n]) && (n < 27))
		n++;
	if (n == 18)
	{
		ft_n_type(command, ap, len);
		return (len);
	}
	if (n == 27)
		return (0);
	aux = (*g_type_func[n])(command, ap, res, len);
	ft_strdel(&command);
	return (aux);
}

static int		ft_printf_body(va_list *ap, const char *str, char **res)
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
		ft_memmove(aux_res + len, head, aux_len);
		if ((aux_len = exec_command(aux_str, ap, len + aux_len, &aux_res)) < 0)
			return (-len);
		len = aux_len;
		ft_strdel(res);
		*res = aux_res;
		head = aux_str + find_end(aux_str) + 1;
		if (!*aux_str)
			break ;
	}
	return (len);
}

int				ft_sprintf(char *buff, const char *str, ...)
{
	char		*res;
	va_list		ap[2];
	int			len;

	len = 0;
	va_start(ap[0], str);
	va_copy(ap[1], ap[0]);
	res = NULL;
	len = ft_printf_body(ap, str, &res);
	if (len < 0)
	{
		write(1, res, -len);
		len = -1;
	}
	else if (len == 0 && !res)
		return (-1);
	else
	{
		res = ft_colors(res, (size_t *)(&len));
		ft_memcpy(buff, res, len);
	}
	va_end(ap[0]);
	va_end(ap[1]);
	ft_strdel(&res);
	return (len);
}
