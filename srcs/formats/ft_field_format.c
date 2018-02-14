/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:13:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/14 23:32:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int		size(char **command, unsigned int len)
{
	unsigned int	start;
	unsigned int	end;

	while ((len + 1) > 0)
	{
		if ((*command)[len] == '*')
		{
			
			start = len;
			end = len + 1;
			break ;
		}
		if (ft_isdigit((*command)[len]))
		{
			end  = len + 1;
			while (ft_isdigit((*command)[--len]));
			start = len + 1;
			if ((*command)[len] == '*' && (*command)[end] == '$')
			{
				start--;
				end++;
			}
			break ;
		}
		len--;
	}
}

static int		cuant(char *command, unsigned int len)
{
	unsigned int	start;
	unsigned int	end;

	while ((len + 1) > 0)
	{
		if (command[len] == '.')
		{
			start = len++;
			if (command[len] == '*')
				end = ++len;
			while (ft_isdigit(command[len++]));
			if (command[start + 1] == '*')
			{
				if (command[len] == '$')
					end = len + 1;
			}
			else
				end = len;
			break ;
		}
	}
}

void			ft_field_format(int *size_cuant,
			                char *command, va_list ap, va_list ap2)
{
	unsigned int	len;
	
	len = ft_strlen(*command) - 2;
	size_cuant[0] = -1;
	while (size_cuant[0] == -1)
		size_cuant[0] = size(&command, ap, ap2);
	size_cuant[1] = cuant(command, ap, ap2);
}
