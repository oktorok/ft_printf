/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apostrophe_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 01:35:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 15:03:43 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int cuantity(char *variable)
{
	if (ft_strlen(variable) % 3)
		return (ft_strlen(variable) + ft_strlen(variable) / 3 - 1);
	else
		return (ft_strlen(variable) + ft_strlen(variable) / 3 - 2);
}

char	*ft_apostrophe_format(char *comm, char *variable)
{
	char	*var_head;
	char	*new_variab;
	int		i;
	int		j;

	if (!(ft_strchr(comm, '\'')))
		return (variable);
	i = cuantity(variable);
	if (!(new_variab = ft_strnew(i)))
		return (NULL);
	var_head = variable;
	variable += ft_strlen(variable) - 1;
	j = 0;
	while (i >= 0)
	{
		new_variab[i--] = *variable--;
		if (variable < var_head)
			break ;
		j++;
		if (!(j % 3))
			new_variab[i--] = ',';
	}
	ft_strdel(&var_head);
	return (new_variab);
}
