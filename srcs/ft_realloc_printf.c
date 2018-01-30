/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:48:09 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/30 13:07:30 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_realloc_printf(char *s, char *start, char *end)
{
	char *str;

	if (!start)
	{
		ft_strdel(&s);
		return (NULL);
	}
	if (!end)
	{
		if (!(str = ft_strjoin(s, start)))
			return (NULL);
		ft_strdel(&s);
		ft_strdel(&start);
		return (str);
	}
	if (!(str = ft_strnjoin(s, start, (unsigned int)(end - start))))
		return (NULL);
	ft_strdel(&s);
	return (str);
}
