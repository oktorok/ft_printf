/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/17 19:34:36 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_l_mod(int *siz_cuant, char *command, va_list ap)
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
				return ((mod_func[0])(ap, siz_cuant, command));
			i++;
		}
		j++;
	}
	return (NULL);
}
