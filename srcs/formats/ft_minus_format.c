/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:12:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/16 23:46:21 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_minus_format(char *command)
{
	while (*command)
	{
		if (*command == '-')
			return (1);
		command++;
	}
	return (0);
}
