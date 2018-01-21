/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/19 20:06:19 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_l_mod(int *siz_cuant, char *comm, va_list ap, va_list ap2)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (comm[k] != 'l' && comm[k])
		k++;
	j = 0;
	while (g_length_modifiers[j] && (comm[k] == 'l' && comm[k + 1] != 'l'))
	{
		i = 0;
		while (g_length_modifiers[i][j])
		{
			if (comm[k + 1] == g_length_modifiers[i][j])
				return ((l_mods[0])(ap, ap2, siz_cuant, comm));
			i++;
		}
		j++;
	}
	return (NULL);
}
