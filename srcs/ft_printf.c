/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/15 22:14:41 by jagarcia         ###   ########.fr       */
/*   Updated: 2018/02/15 01:04:51 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		exec_command(char *str, va_list *ap, size_t len, char **res)
{
	char			*command;
	int				aux;
	int				n;

	n = 0;
	if (!str)
		return (len);
	if (!(aux = ft_findend(str)))
		return (len);
	if (!(command = ft_strsub(str, 1, aux)))
		return (-1);
	n = ft_strchr(g_types, str[aux]) - g_types;
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
		aux_str = ft_strchr(head, '%');
		aux_len = (int)((aux_str - head) < 0 ? (int)ft_strlen(head) : aux_str -
		                head);
		aux_res = ft_memmove(ft_strnew(len + aux_len), *res, len);
		ft_memmove(aux_res + len, head, aux_len);
		if ((aux_len = exec_command(aux_str, ap, len + aux_len, &aux_res)) < 0)
			return (-len);
		len = aux_len;
		ft_strdel(res);
		*res = aux_res;
		head = aux_str ? aux_str + ft_findend(aux_str) + 1 : head + ft_strlen(head);
		if (!aux_str)
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
	if (len < 0)
	{
		write(1, res, -len);
		len = -1;
	}
	else if (len == 0 && !res)
		return (-1);
	else
		write(1, res, len);
	va_end(ap[0]);
	va_end(ap[1]);
	ft_strdel(&res);
	return (len);
}
