/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:12:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/21 03:19:38 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_zero_format(char *command)
{
	while (*command)
	{
		if (ft_isdigit(*command) && *command != '0')
			return (0);
		if (*command == '0')
		{
			while (*command)
				if (*command++ == '.')
					return (0);
			return (1);
		}
		command++;
	}
	return (0);
}
