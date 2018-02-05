/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:06:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 05:02:01 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int		ft_mods(char *comm)
{
	int		i;

	i = 0;
	while (*mods[i])
	{
		if (ft_strstr(comm, mods[i]) && *mods[i])
			return (i + 1);
		i++;
	}
	return (0);
}
