/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:58:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 07:08:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_ajust_params(char *comm, int *siz_cuant, char *variable)
{
	int len;

	if (!siz_cuant[1] && *variable == '0')
		*variable = '\0';
	len = ft_strlen(variable);
	if (siz_cuant[1] >= 0)
	{
		if (siz_cuant[1] <= len)
			siz_cuant[1] = 0;
		else
			siz_cuant[1] -= len;
		if (siz_cuant[0] < len + siz_cuant[1])
			siz_cuant[0] = len + siz_cuant[1];
	}
	else
	{
		siz_cuant[1] = 0;
		if (siz_cuant[0] < len)
			siz_cuant[0] = len;
		if (ft_search_zero_format(comm))
			siz_cuant[1] = siz_cuant[0] - len;
	}	
}
