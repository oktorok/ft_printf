/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sige.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:57:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/19 18:55:04 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_sige(double x)
{
	if (x > (int)x || x < (int)x)
		return ((double)((int)x + 1));
	else
		return (x);
}