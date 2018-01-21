/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apostrophe_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 01:35:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/21 02:22:33 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apostrophe_format(char *comm, char *variable)
{
	int		cuant;
	char	*new_variab;
	int		i;
	int		j;

	while (*comm != '\'')
		if (!(*comm++))
			return (variable);
	cuant = ft_strlen(variable) / 4;
	i = ft_strlen(variable) + cuant - 1;
	new_variab = ft_strnew(i + 1);
	variable += ft_strlen(variable) - 1;
	j = 0;
	while (i >= 0)
	{
		new_variab[i--] = *variable--;
		j++;
		if (!(j % 3))
			new_variab[i--] = ',';
	}
	variable++;
	ft_strdel(&variable);
	return (new_variab);
}
