/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/16 23:51:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		take_num(char **comm, int i, va_list *ap, int cas);

static int		take_size(char **command, va_list *ap)
{
	int		len;

	len = ft_strlen(*command) - 1;
	while (len >= 0)
	{
		if ((*command)[len] == '$')
			while (ft_isdigit((*command)[--len]) && len >= 0);
		if ((*command)[len] == '*' && ((*command)[len - 1] != '.' || len - 1 < 0))
			break ;
		else if (ft_isdigit((*command)[len]))
		{
			while (ft_isdigit((*command)[len]) && len >= 0)
				len--;
			if ((*command)[len] != '.')
			{
				len++;
				break ;
			}
		}
		if ((*command)[len] != '$' && len >= 0)
			len--;
	}
	if ((*command)[len] == '*')
		return(take_num(command, len, ap, 0));
	return (ft_atoi(*command + len));
}

static int		take_cuant(char **command, va_list *ap)
{
	int		len;

	len = ft_strlen(*command) - 1;
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
	*comm = ft_strinsertfree(ft_strcutfree(*comm, i, i + 1), ft_itoa(aux), i);
	if (cas)
		return (take_cuant(comm, ap));
	return (take_size(comm, ap));
}

void			ft_field_format(int *size_cuant,
		char **command, va_list *ap)
{
	size_cuant[0] = take_size(command, ap);
	size_cuant[1] = take_cuant(command, ap);
}
