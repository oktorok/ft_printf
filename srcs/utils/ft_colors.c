/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 04:29:17 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/05 05:05:48 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char		check_arr(char type, char *str, size_t pos, size_t i)
{
	char	j;
	char	*aux;

	j = 0;
	aux = ft_strsub(str, pos, i);
	while (j < 10)
	{
		if (ft_strcmp(type ? g_colors[j] : g_formats[j], aux))
		{
			ft_strdel(&aux);
			return (1);
		}
		j++;
	}
	if (atoi(aux) <= (type ? 255 : 9))
	{
		ft_strdel(&aux);
		return (2);
	}
	ft_strdel(&aux);
	return (0);
}

static size_t	check_com(char *str, size_t pos, size_t len)
{
	size_t	i;
	char	bool;

	bool = 0;
	i = pos;
	while (i < len)
	{
		if (str[i] == ',')
		{
			if (!(check_arr(0, str, pos, i)) || bool++)
				return (0);
			pos = i + 1;
		}
		if (str[i] == '}')
		{
			if ((check_arr(1, str, pos, i) && bool) ||
			    ((check_arr(1, str, pos, i) ||
			      check_arr(0, str, pos, i)) && !bool))
				return (i);
			return (0);
		}
		i++;
	}
	return (0);
}

static char		*select_num(char type, char *str, size_t start, size_t end)
{
	char	*aux;
	char	i;

	aux = ft_strsub(str, start, end);
	i = 0;
	while (i < (type ? 8 : 10))
	{
		if (ft_strcmp(type ? g_colors[i] : g_formats[i], aux))
		{
			aux[0] = type ? 'm' : ';';
			aux[1] = '\0';
			return (ft_strjoinfree(ft_itoa(i), aux));
		}
		i++;
	}
	i = ft_atoi(aux);
	aux[0] = type ? 'm' : ';';
	aux[1] = '\0';
	return (ft_strjoinfree(ft_itoa(i), aux));
}

static char		*apply_com(char *str, size_t start, size_t end, size_t *len)
{
	char	*new;
	char	*aux;
	char	*res;

	new = ft_strcpy(ft_strnew(5), "\033[");
	aux = ft_strchr(str + start + 1, ','); 
	if (aux)
		new = ft_strjoinfree(new, select_num(0, str, start + 1, (size_t)((aux + 1) - str)));
	new = ft_strjoinfree(new, ft_strcpy(ft_strnew(5), "38;5;"));
	new = ft_strjoinfree(new, select_num(1, str, (size_t)((aux + 1) - str), end));
	*len = *len - (end - start) + ft_strlen(new);
	res = ft_strnew(*len);
	res = ft_strncpy(res, str, start);
	res = ft_strcat(res, new);
	res = ft_strcat(res, str + end);
	ft_strdel(&new);
	return (res);
}

char			*ft_colors(char *str, size_t len)
{
	size_t	i;
	size_t	end;

	i = 0;
	while (i < len)
	{
		if (str[i] == '{')
		{
			if ((end = check_com(str, i + 1, len)))
			{
				str = apply_com(str, i, end, &len);
				i = end;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (str);
}
