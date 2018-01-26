/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apostrophe_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 01:35:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/26 21:51:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apostrophe_format(char *comm, char *variable)
{
	char	*var_head;
	char	*new_variab;
	int		i;
	int		j;

	while (*comm != '\'')
		if (!(*comm++))
			return (variable);
	i = ft_strlen(variable) + ft_strlen(variable) / 3 - 2;
	new_variab = ft_strnew(i + 1);
	var_head = variable;
	variable += ft_strlen(variable) - 1;
	j = 0;
	while (i >= 0)
	{
		new_variab[i--] = *variable--;
		j++;
		if (!(j % 3) && (i != 0))
			new_variab[i--] = ',';
	}
	variable++;
	ft_strdel(&var_head);
	return (new_variab);
}
