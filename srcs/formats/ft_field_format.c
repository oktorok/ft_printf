/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/15 01:49:16 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char		*cut(char **comm, int start, int end)
{
	char	*sub;

	sub = ft_strsub(*comm, start, end);
	*comm = ft_strcutfree(*comm, start, end);
	return (sub);
}

static int		ft_select(char *comm, int end, va_list ap, va_list ap2)
{
	int res;
	
	if (!comm)
		return (0);
	if (comm[0] == '*' && comm[end] == '$')
		res = *((int * )ft_locate_date(comm, 5, ap, ap2));
	else if (comm[0] == '*')
		res = va_arg(ap2, int);
	else
		res = ft_atoi(comm);
	ft_strdel(&comm);
	return (res);
}

static int		size(char **command, unsigned int len, va_list ap, va_list ap2)
{
	int		end;

	while ((len + 1) > 0)
	{
		if ((*command)[len] == '*')
			return (ft_select(cut(command, len, len + 1), len, ap, ap2));
		if (ft_isdigit((*command)[len]))
		{
			end  = len + 1;
			while (ft_isdigit((*command)[--len]));
			if ((*command)[len] == '*' && (*command)[end] == '$')
				return (ft_select(cut(command, len, end + 1), end, ap, ap2));
			else
				return (ft_select(cut(command, len + 1, end), end - 1, ap, ap2));
		}
		len--;
	}
	return (0);
}

static int		cuant(char **command, unsigned int len, va_list ap, va_list ap2)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	while ((len + 1) > 0)
	{
		if ((*command)[len] == '.')
		{
			start = ++len;
			if ((*command)[len] == '*')
				end = ++len;
			while (ft_isdigit((*command)[len]))
				len++;
			if ((*command)[start] == '*')
			{
				if ((*command)[len] == '$')
					end = len + 1;
			}
			else
				end = len;
			break ;
		}
		len--;
	}
return (ft_select(cut(command, start, end), end - 1, ap, ap2));
}

void			ft_field_format(int *size_cuant,
			                char *command, va_list ap, va_list ap2)
{
	unsigned int	len;

	len = ft_strlen(command) - 2;
	size_cuant[0] = -1;
	size_cuant[1] = cuant(&command, len, ap, ap2);
	while (size_cuant[0] == -1)
		size_cuant[0] = size(&command, len, ap, ap2);
}
