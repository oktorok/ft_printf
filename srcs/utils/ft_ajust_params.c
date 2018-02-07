/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:58:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 07:34:04 by jagarcia         ###   ########.fr       */
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
	else if (siz_cuant[0] < len)
			siz_cuant[0] = len;
}
