/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/18 20:01:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_locate_variable(char *comm, va_list ap, va_list ap2)
{
	int		loc;
	int		i;
	va_list ap3;
	void 	*variable;

	while (*comm != '*' && *comm != '$' && *comm)	/* solo leo el primer dolar por lo que hay que mover comando antes de enviarlo aqui */
		comm++;
	if (*comm-- != '$')
		return (va_arg(ap2, void *));
	va_copy(ap3, ap);
	while (ft_isdigit(*comm))
		comm--;
	loc = ft_atoi(++comm);
	while (loc > 1)
	{
		va_arg(ap3, void *); /* leaks quiza? */
		loc--;
	}
	variable = va_arg(ap3, void *);
	va_end(ap3);
	return (variable);
}
