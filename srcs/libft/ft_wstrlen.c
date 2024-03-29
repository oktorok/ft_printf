/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:25:35 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 04:01:10 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *str)
{
	size_t		i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			i++;
			str++;
		}
	}
	return (i);
}
