/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 05:40:10 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_l_func(int *siz_cuant, char *command, void *variable)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (command[k] != 'l' && command[k])
		k++;
	j = 0;
	while (g_length_modifiers[j] && (command[k] == 'l' && command[k + 1] != 'l'))
	{
		i = 0;
		while (g_length_modifiers[i][j])
		{
			if (command[k + 1] == g_length_modifiers[i][j])
				return ((mod_func[0])(variable, siz_cuant, command));
			i++;
		}
		j++;
	}
	return (NULL);
}
