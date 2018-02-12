/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/12 15:46:22 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

static char	*for_f(char *str, int *siz_cuant)
{
	char	*new;
	int		pos;

	pos = (ft_strchr(str, 'e') - str - 1) + ft_atoi(ft_strchr(str, 'e') + 1);
	if (!(new = ft_strnew(ft_strlen(str) + 1 + ((pos < 0) ? (-pos) : 0))))
		return (NULL);
	if (pos < 0)
		ft_memset(new, '0', -pos + 1);
	else
		ft_strncpy(new, str, pos + 1);
	new[(pos < 0) ? 1 : (pos + 1)] = '.';
	ft_strcpy(new + ((pos < 0) ? (-pos + 1) : (pos + 2)), str +
				((pos < 0) ? 0 : (pos + 1)));
	new = ft_strsub(new, 0, ft_strchr(new, '.') - new + siz_cuant[1]);
	ft_strdel(&str);
	return (new);
}

static char	*for_e(char *str, int *siz_cuant)
{
	char	*new;
	char	*aux;
	int		len;

	len = (ft_strchr(str, 'e') - str - 1) + ft_atoi(ft_strchr(str, 'e') + 1);
	if (!(new = ft_memset(ft_strnew(siz_cuant[1] + 5), '0', siz_cuant[1] + 5)))
		return (NULL);
	new[0] = str[0];
	new[1] = '.';
	ft_strncpy(new + 2, str + 1, siz_cuant[1] - 1);
	new[siz_cuant[1] + 1] = 'e';
	new[siz_cuant[1] + 2] = (len < 0) ? '-' : '+';
	aux = ft_itoa(ft_abs(len));
	ft_strcpy(new + ((ft_abs(len) > 9) ? 3 : 4) + siz_cuant[1], aux);
	ft_strdel(&aux);
	siz_cuant[1] += 4;
	return (new);
}

static char	*for_g(char *str, int *siz_cuant)
{
	int		len;
	char	*new;
	char	*aux;

	len = (ft_strchr(str, 'e') - str - 1) + ft_atoi(ft_strchr(str, 'e') + 1);
	if (len < -4 || len >= (siz_cuant[1] - 1))
	{
		new = for_e(str, siz_cuant);
		len = ft_strchr(new, 'e') - new - 1;
		while (len >= 0 && (new[len] == '0' || new[len] == '.'))
			len--;
		aux = ft_strncpy(ft_strnew(len + 5), new, len + 1);
		ft_strcpy(aux + (len + 1), ft_strchr(new, 'e'));
		ft_strdel(&new);
		return (aux);
	}
	else
	{
		new = for_f(str, siz_cuant);
		len = ft_strlen(new) - 1;
		while (len >= 0 && (new[len] == '0' && new[len] != '.'))
			new[len--] = 0;
		new[len] = (new[len] == '.') ? 0 : new[len];
		return (new);
	}
}

char		*ft_putthepoint(char *str, int *siz_cuant, char *comm)
{
	char	type;

	type = ft_toupper(comm[ft_strlen(comm) - 1]);
	if (type == 'F')
		return (for_f(str, siz_cuant));
	if (type == 'E')
		return (for_e(str, siz_cuant));
	return (for_g(str, siz_cuant));
}
