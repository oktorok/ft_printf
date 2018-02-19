/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:48:56 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/19 11:02:56 by jagarcia         ###   ########.fr       */
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

char		*ft_round(char *str, int pos)
{
	char	ac;

	if (!ft_isdigit(str[pos]) || pos > (int)ft_strlen(str) - 3)
		return (str);
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
