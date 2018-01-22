/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sige.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:57:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 17:53:19 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

double	ft_sige(double x)
{
	if (x >= 0)
	{
		if (x > (int)x)
			return ((double)((int)x + 1));
	}
	return ((double)((int)x));
}
