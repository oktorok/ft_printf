/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 02:34:47 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		box_size(char *dot_pos, int *size_cuant)
{
	if (ft_isdigit(*dot_pos))
	{
		if (ft_atoi(dot_pos) < size_cuant[1])
			size_cuant[0] = size_cuant[1];
		else
			size_cuant[0] = ft_atoi(dot_pos);
	}
	else
		size_cuant[0] = size_cuant[1];

}

static void		precision(char *num_pos, int *size_cuant, int length)
{
	if (num_pos && *num_pos == '.' && !size_cuant[1])
	{
		if (!ft_isdigit(*(num_pos + 1)))
			size_cuant[1] = 0;
		else if (ft_atoi(num_pos + 1) > length)
			size_cuant[1] = length;
		else
			size_cuant[1] = ft_atoi(num_pos + 1);
	}
	else if (!size_cuant[1])
		size_cuant[1] = length;

}
void			ft_field_func(int *size_cuant, char *command, char *variable)
{	
	char	*aux;
	int		length;

	length = ft_strlen(variable);
	aux = ft_strchr(command, '.');
	precision(command, size_cuant, length);
	while (!ft_isdigit(*command) && command != aux  && *command)
		command++;
	box_size(command, size_cuant);
}
