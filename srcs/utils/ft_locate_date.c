/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/19 18:16:25 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		*selector(int mem, va_list ap)
{
	void *variable;

	variable = ft_memalloc(mem);
	if (mem - 1 == 1)
		*((char *)variable) = va_arg(ap, int);
	else if (mem == 4)
		*((int *)variable) = va_arg(ap, int);
	else if (mem - 1 == 4)
		*((wchar_t *)variable) = va_arg(ap, wchar_t);
	return (variable);
}

void			*ft_locate_date(char *comm, int mem, va_list ap, va_list ap2)
{
	int		loc;
	int		i;
	va_list	ap3;
	void	*variable;

	while (*comm != '*' && *comm != '$' && *comm)
		comm++;
	if (*comm-- != '$')
	{
		variable = selector(mem, ap2);
		return (variable);
	}
	va_copy(ap3, ap);
	while (ft_isdigit(*comm))
		comm--;
	loc = ft_atoi(++comm);
	while (loc > 1)
	{
		va_arg(ap3, void *);
		loc--;
	}
	variable = selector(mem, ap3);
	va_end(ap3);
	return (variable);
}
