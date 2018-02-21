/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/21 20:34:54 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int		take_size(char *comm, int len)
{
	while (len >= 0)
	{
		if (comm[len] == '$')
		{
			while (ft_isdigit(comm[--len]) && len >= 0)
				len--;
		}
		else if (ft_isdigit(comm[len]))
		{
			while ((ft_isdigit(comm[len]) || comm[len] == '-') && len >= 0)
				len--;
			if (comm[len] != '.')
			{
				len++;
				break ;
			}
		}
		if (comm[len] != '$' && len >= 0)
			len--;
	}
	return (ft_atoi(comm + (len < 0 ? 0 : len)));
}

static int		take_cuant(char *command, int len)
{
	while (command[len] != '.' && len >= 0)
		len--;
	if (len >= 0)
		return (ft_atoi(command + len + 1));
	return (-1);
}

void			ft_field_format(int *size_cuant,
		char **command, va_list *ap)
{
	int		len;

	if (ft_strchr(*command, '*'))
		ft_asterisc_format(command, ap);
	len = ft_strlen(*command) - 1;
	size_cuant[0] = take_size(*command, len);
	size_cuant[1] = take_cuant(*command, len);
}
