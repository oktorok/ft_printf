/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisc_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:05:12 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/21 20:20:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		modify_comm(char **command, int pos, int dolar, va_list *ap)
{
	void	*tmp;
	int		aux;
	char	*inser;

	if (!dolar)
		aux = va_arg(ap[1], int);
	else
	{
		tmp = ft_locate_date(*command + pos + 1, 5, ap[0], ap[1]);
		aux = *((int *)tmp);
		ft_memdel(&tmp);
	}
	inser = ft_strjoinfree(ft_itoa(aux), ft_strdup(","));
	*command = ft_strcutfree(*command, pos, pos + 1);
	*command = ft_strinsertfree(*command, inser, pos);
}

void	ft_asterisc_format(char **command, va_list *ap)
{
	char	*tmp;
	int		i;

	tmp = *command;
	while ((tmp = ft_strchr(tmp, '*')))
	{
		if (ft_isdigit(tmp[1]) && tmp[1] != 0)
		{
			i = 1;
			while (ft_isdigit(tmp[i]))
				i++;
			if (tmp[i] == '$')
				modify_comm(command, tmp - *command, i, ap);
			else
				modify_comm(command, tmp - *command, 0, ap);
		}
		else
			modify_comm(command, tmp - *command, 0, ap);
	}
}
