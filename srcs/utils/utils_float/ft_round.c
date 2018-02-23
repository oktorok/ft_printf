/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:48:56 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/23 19:19:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*resize_str(char *str, char ac)
{
	char	*new;

	if (ac)
	{
		if (!(new = ft_strnew(ft_strlen(str) + 1)))
			return (NULL);
		new[0] = '1';
		ft_strcpy(new + 1, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

static char	*apply_round(char *str, int pos)
{
	char	ac;

	ac = 0;
	while ((pos + 1) > 0)
	{
		if ((str[pos] >= '5' || ac) && pos >= 0)
		{
			pos--;
			if (++(str[pos]) > '9')
			{
				str[pos] = '0';
				ac = 1;
			}
			else
			{
				ac = 0;
				break ;
			}
		}
		else
			break ;
	}
	return (resize_str(str, ac));
}

char		*ft_round(char *str, int pos)
{
	char	*e_pos;

	e_pos = ft_strchr(str, 'e'); 
	pos = pos + (e_pos - str) + ft_atoi(e_pos + 1) - pos ? 1 : 0;
	if (pos > (int)ft_strlen(str) - 3)
		return (str);
	return (apply_round(str, pos));
}
