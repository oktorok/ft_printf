/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:06:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/20 20:11:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_mods(int *siz_cuant, char *comm, va_list ap, va_list ap2)
{
	int		i;
	
	i = 0;
	while (mods[i])
	{
		if (ft_strstr(comm, mods[i]))
			return(i);
		i++;
	}
	return (-1);
}
