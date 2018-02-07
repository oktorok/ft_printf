/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/07 05:41:43 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

char	*ft_putthepoint(char *str, size_t pos)
{
	char	*new;

	if (!(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	ft_strncpy(new, str, pos + 1);
	new[pos + 1] = '.';
	ft_strcpy(new + pos + 2, str + pos + 1);
	return (new);
}
