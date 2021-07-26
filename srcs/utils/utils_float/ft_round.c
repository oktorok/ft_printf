/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:48:56 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/23 19:31:08 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*resize_str(char *str, char ac)
{
	char	*new;

	if (ac)
	{
		new = ft_strnew(ft_strlen(str) + 1);
		if (!new)
			return (NULL);
		new[0] = '1';
		ft_strcpy(new + 1, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

static char	*apply_round(char *str, int pos, char is_neg)
{
	char	ac;

	str = str + is_neg;
	ac = 0;
	while ((pos + 1) > 0)
	{
		if ((str[pos] >= '5' || ac) && pos >= 0)
		{
			pos--;
			if (++(str[--pos]) > '9')
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
	str = str - is_neg;
	return (resize_str(str, ac));
}

char	*ft_round(char *str, int pos, char *comm)
{
	char	*e_pos;

	if (ft_toupper(comm[ft_strlen(comm) - 1]) == 'F')
	{
		e_pos = ft_strchr(str, 'e');
		pos = pos + e_pos - str + ft_atoi(e_pos + 1);
		if (pos)
			pos -= 1;
	}
	if (pos > (int)ft_strlen(str) - 3)
		return (str);
	if (*str == '-')
		return (apply_round(str, pos, 1));
	else
		return (apply_round(str, pos, 0));
}
