/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:41:32 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/05 15:57:23 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*an_space(char *str)
{
	char *new_str;

	if (*(str + 1) == '-')
	{
		if (!(new_str = ft_strdup(str + 1)))
			return (NULL);
	}
	else
		if (!(new_str = ft_strjoin("+", str + 1)))
			return (NULL);
	ft_strdel(&str);
	return (new_str);
}

char	*ft_plus_format(char *command, char *str, int *siz_cuant)
{
	char	*new_str;
	int		i;

	i = 0;
	while (command[i] && *str != '-')
	{
		if (command[i++] == '+')
		{
			if (*str == ' ')
				return (an_space(str));
			if (ft_zero_format(command) && (*str == '0')
					&& (ft_isdigit(*(str + 1))))
			{
			   	*str = '+';
		   		return (str);
			}
			if (!(siz_cuant[0] >= ft_strlen(str) + 1))
				siz_cuant[0]++;
			if (!(new_str = ft_strjoin("+", str)))
				return (NULL);
			ft_strdel(&(str));
			return (new_str);
		}
	}
	return (str);
}
