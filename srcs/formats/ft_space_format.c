/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:28:21 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/21 03:13:03 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_space_format(char *command, char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == '-')
			return (str);
	while (*command && *str != ' ')
	{
		if (*command++ == ' ')
		{
			if (*str == '0')
			{
				*str = ' ';
				return (str);
			}
			new_str = ft_strjoin(" ", str);
			ft_strdel(&str);
			return (new_str);
		}
	}
	return (str);
}
