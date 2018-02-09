/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commexecuter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:22:15 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/09 16:35:22 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_commexecuter(char *comm, va_list *ap, char **res, size_t len)
{
	char	i;

	while (*comm)
	{
		i = 0;
		while (g_types[i] != *comm && i < 27)
			i++;
		if (i < 27)
			(type_function[i])(comm, ap, res, len);
	}
}
