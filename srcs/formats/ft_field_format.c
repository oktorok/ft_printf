/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 12:40:57 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		take_num(char **comm, int i, va_list *ap, int cas)
{
	void	*tmp;
	int		aux;

	if (ft_isdigit((*comm)[i + 1]))
	{
		if (!(tmp = ft_locate_date(*comm + i + 1, 5, ap[0], ap[1])))
			return (-2);
		aux = *((int *)tmp);
		ft_memdel(&tmp);
	}
	else
		aux = va_arg(ap[1], int);
	if (!(*comm = ft_strcutfree(*comm, i, i + 1)))
		return (-2);
	if (cas)
		if (!(*comm = ft_strinsertfree(*comm, ft_itoa(aux), i)))
			return (-2);
	if (aux < 0)
	{
		aux = -aux;
		if (!(*comm = ft_strinsertfree(*comm, ft_strdup("-"), i)))
			return (-2);
	}
	return (aux);
}

static int		take_size(char **comm, va_list *ap, int len)
{
	while (len >= 0)
	{
		if ((*comm)[len] == '$')
		{
			while (ft_isdigit((*comm)[--len]) && len >= 0)
				len--;
		}
		if ((*comm)[len] == '*' && ((*comm)[len - 1] != '.' || len - 1 < 0))
			break ;
		else if (ft_isdigit((*comm)[len]))
		{
			while (ft_isdigit((*comm)[len]) && len >= 0)
				len--;
			if ((*comm)[len] != '.')
			{
				len++;
				break ;
			}
		}
		if ((*comm)[len] != '$' && len >= 0)
			len--;
	}
	if ((*comm)[len] == '*')
		return (take_num(comm, len, ap, 0));
	return (ft_atoi(*comm + len));
}

static int		take_cuant(char **command, va_list *ap, int len)
{
	while ((*command)[len] != '.' && len >= 0)
		len--;
	if (len >= 0)
	{
		if ((*command)[len + 1] == '*')
			return (take_num(command, len + 1, ap, 1));
		return (ft_atoi(*command + len + 1));
	}
	return (-1);
}

void			ft_field_format(int *size_cuant,
		char **command, va_list *ap)
{
	int		len;

	len = ft_strlen(*command) - 1;
	size_cuant[0] = take_size(command, ap, len);
	size_cuant[1] = take_cuant(command, ap, len);
}
