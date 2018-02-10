/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/10 06:30:43 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_putthepoint(char *str, int *siz_cuant)
{
	char	*new;
	size_t	pos;

	pos = (ft_strchr(str, 'e') - str - 1) + ft_atoi(ft_strchr(str, 'e') + 1);
	if (!(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	ft_strncpy(new, str, pos + 1);
	new[pos + 1] = '.';
	ft_strcpy(new + pos + 2, str + pos + 1);


	///
	new = ft_strsub(new, 0, ft_strchr(new, '.') - new + siz_cuant[1]);
	///
	return (new);
}
