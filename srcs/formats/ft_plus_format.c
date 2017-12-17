/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:41:32 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/17 08:28:35 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_plus_format(char *command, char *str)
{
	char *new_str;

	while (*command && *str != '-')
	{
		if (*command == '+')
		{
			if (*str = ' ')
			{
				if ((str + 1) == '-')
					new_str = ft_strdup(str + 1);
				else
					new_str = ft_strjoin("+", str + 1);
				ft_strdel(&str);
				return (new_str);
			}
			new_str = ft_strjoin("+", str);
			ft_strdel(&(str));
			return (new_str);
		}
		command++;
	}
	return (str);
}