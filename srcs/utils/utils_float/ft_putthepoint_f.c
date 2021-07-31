/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/23 17:59:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*negative_pos(char *str, int pos, int tmp)
{
	char	*new;

	new = ft_strnew(ft_strlen(str) + 1 - pos + tmp);
	if (!new)
		return (NULL);
	ft_memset(new, '0', ft_strlen(str) + 1 - pos + tmp);
	new[1] = '.';
	ft_strncpy(new - pos + 1, str, ft_strlen(str));
	return (new);
}

static char	*positive_pos(char *str, int pos, int tmp)
{
	char	*new;

	new = ft_strnew(ft_strlen(str) + 1 + tmp);
	if (!new)
		return (NULL);
	ft_memset(new, '0', ft_strlen(str) + 1 + tmp);
	ft_strncpy(new, str, pos + 1);
	new[pos + 1] = '.';
	ft_strncpy(new + pos + 2, str + pos + 1, ft_strlen(str + pos + 1));
	return (new);
}

char	*for_f(char *str, int *siz_cuant)
{
	char	*new;
	int		pos;
	char	*aux;
	int		tmp;

	aux = ft_strchr(str, 'e');
	pos = aux - str - 1 + ft_atoi(aux + 1);
	ft_memset(aux, '0', ft_strlen(aux));
	tmp = 0;
	if (ft_abs((pos + 1) % ft_strlen(str)) < siz_cuant[0])
		tmp = siz_cuant[1] - ft_abs((pos + 1) % ft_strlen(str));
	if (pos < 0)
	{
		new = negative_pos(str, pos, tmp);
		if (!new)
			return (NULL);
	}
	else
	{
		new = positive_pos(str, pos, tmp);
		if (!new)
			return (NULL);
	}
	new = ft_strsub(new, 0, ft_strchr(new, '.') - new + siz_cuant[1]);
	return (new);
}
