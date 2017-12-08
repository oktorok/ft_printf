/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:48:09 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/08 03:04:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_realloc_printf(char *dst, char *src)
{
	if (!dst)
	{
		if (!(dst = ft_strdup(src)))
			return (NULL);
		return (dst);
	}
	if (!(dst = ft_strjoin(dst, src)))
		return (NULL);
	return (dst);
}
