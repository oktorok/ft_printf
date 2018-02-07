/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:48:56 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/07 06:59:50 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

static char	*resize_str(char *str, char ac)
{
	char	*new;

	if (ac)
	{
		if (!(new = ft_strnew(ft_strlen(str) + 1)))
			return (NULL);
		new[0] = 1;
		ft_strcpy(new + 1, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

char		*ft_round(char *str, size_t pos)
{
	char	ac;

	if (ft_isdigit(str[pos + 1]))
		pos++;
	ac = 0;
	while ((pos + 1) > 0)
	{
		if (str[pos--] >= '5' || ac)
		{
			str[pos] = str[pos] + 1;
			if (str[pos] > '9')
			{
				str[pos] = 0;
				ac = 1;
			}
			else
			{
				ac = 0;
				break ;
			}
		}
	}
	return (resize_str(str, ac));
}
