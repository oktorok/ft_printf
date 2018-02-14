/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:23:20 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/13 18:32:33 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cutstr(char *str, int start, int end)
{
	char	*new;

	if (end <= start)
		return (str);
	if (!(new = ft_strnew(ft_strlen(str) - (end - start))) || !str)
		return (NULL);
	ft_strncpy(new, str, start);
	ft_strcat(new, str + end);
	return (new);
}
