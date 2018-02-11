/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/10 19:14:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

char	*ft_putthepoint(char *str, int *siz_cuant)
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
	ft_strcpy(new + ((pos < 0) ? (-pos + 1) : (pos + 2)), str + ((pos < 0) ? 0 : (pos + 1)));
	///
	new = ft_strsub(new, 0, ft_strchr(new, '.') - new + siz_cuant[1]);
	ft_putstr(new);
	ft_putstr("\n");
	///
	return (new);
}
