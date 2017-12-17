/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 06:28:21 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/17 08:22:44 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_space_format(char *command, char *str)
{
	char	*new_str;

	while (*command && *str != ' ')
	{
		if (*command == ' ')
		{
			new_str = ft_strjoin(" ", str);
			ft_strdel(&str);
			return (new_str);
		}
		command++;
	}
	return (str);
}
