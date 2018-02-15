/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:33:41 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/15 22:18:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char		ft_check(char *str, unsigned int end)
{
	int pos;
	
	if (ft_strchr(g_format, str[end]))
		return (1);
	else if (ft_isdigit(str[end]))
		return (1);
	else if (str[end] == '$')
	{
		while (ft_isdigit(str[--end]));
		if (str[end] == '.' || str[end + 1] == '$')
			return (0);
		return (1);
	}
	else
	{
		pos = 0;
		while (ft_strncmp(g_mods[pos], str + end, ft_strlen(g_mods[pos])))
			pos++;
		if (pos == 6)
			return (0);
		return (1);
	}
	return (0);
}

int				ft_findend(char *str)
{
	unsigned int	end;
	
	end = 1;
	while (str[end])
	{
		if (ft_strchr(g_types, str[end]))
			return (end);
		else if (ft_check(str, end))
			end++;
		else
			return (end - 1);
	}
	if (!str[end])
		return (0);
	return (end);
}
