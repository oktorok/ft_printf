/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:10:07 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 02:53:12 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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

static char				selec_fun(char c)
{
	char	i;

	i = 0;
	while ((c != g_types[i]) && (i < 26))
		i++;
	return (i);
}

static char				*exec_command(char **str, va_list ap)
{
	char			*command;
	char			*res;
	char			n;

	command = ft_strsub(*str, 1, find_end(str));
	if ((n = selec_fun(*(*str - 1))) == 26)
		return (NULL);
	res = (*type_function[n])(command, ap);
	ft_strdel(&command);
	return (res);
}

int						ft_printf(const char *str, ...)
{
	char		*res;
	char		*head_str;
	char		*aux_str;
	va_list		ap;

	va_start(ap, str);
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
							exec_command(&aux_str, ap), NULL)))
				return (-1);
		head_str = aux_str;
		if (!(*aux_str))
			break ;
	}
	ft_putstr(res);
	va_end(ap);
	return (1);
}
