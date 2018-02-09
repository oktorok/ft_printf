/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcomm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:35:44 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/09 18:13:33 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	ft_checkcomm(char *comm)
{
	char	i;
	char	bool;

	bool = 0;
	while (*comm)
	{
		i = 0;
		while (((bool ? *g_mods[i] : *g_format[i]) != *comm) && i < (bool ? 6 : 8))
			i++;
		if (i == (bool ? 6 : 8))
		{
			if (bool)
				break ;
			else if (ft_isdigit(*comm))
				comm++;
			else
				bool = 1;
		}
		else
			comm++;
	}
	if (comm + 1)
		return (0);
	return (1);
}
