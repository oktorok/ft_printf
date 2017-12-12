/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/11 21:40:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_field_func(int *size_cuant, char **command)
{
	if ((size_cuant[0] = size_cuant[1]) < ft_atoi(*command))
		size_cuant[0] = ft_atoi(*command);
	while (ft_isdigit(**command))
		(*command)++;
	if (**command == '.')
	{
		(*command)++;
		size_cuant[1] = ft_atoi(*command);
	}
	while (ft_isdigit(ft_atoi(*command)))
		(*command)++;
}
