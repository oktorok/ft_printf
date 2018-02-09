/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:28:21 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/08 17:52:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_space_format(char *command, char *str, int *siz_cuant)
{
	char	*new_str;
	int		i;

	i = 0;
	while (command[i] && *str != '-')
	{
		if (command[i++] == ' ')
		{
			if (ft_search_zero_format(command) && (*str == '0') &&
					(ft_isdigit(*(str + 1))) && siz_cuant[1] == -1)
			{
				*str = ' ';
				return (str);
			}
			if (!(siz_cuant[0] >= ft_strlen(str) + 1))
				siz_cuant[0]++;
			if (!(new_str = ft_strjoin(" ",str)))
				return (NULL);
			ft_strdel(&str);
			return (new_str);
		}
	}
	return (str);
}
