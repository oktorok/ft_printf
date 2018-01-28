/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/28 21:32:33 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		size(int mem)
{
	if ((mem == 1) || (mem == 2))
		return (sizeof(signed char));
	else if ((mem == 3) || (mem == 4))
		return (sizeof(short));
	else if ((mem == 5) || (mem == 6))
		return (sizeof(int));
	else if (mem == 7)
		return (sizeof(wchar_t));
	else if ((mem == 8) || (mem == 9))
		return (sizeof(long));
	else if ((mem == 10) || (mem == 11))
		return (sizeof(long long));
	else if ((mem == 12) || (mem == 13))
		return (sizeof(intmax_t));
	else if (mem == 14)
		return (sizeof(size_t));
	return (0);
}

static void		*selector2(int mem, va_list ap, void *variable)
{
	if (mem == 8)
		*((long *)variable) = va_arg(ap, long);
	else if (mem == 9)
		*((unsigned long *)variable) = va_arg(ap, unsigned long);
	else if (mem == 10)
		*((long long *)variable) = va_arg(ap, long long);
	else if (mem == 11)
		*((unsigned long long *)variable) = va_arg(ap, unsigned long long);
	else if (mem == 12)
		*((intmax_t *)variable) = va_arg(ap, intmax_t);
	else if (mem == 13)
		*((uintmax_t *)variable) = va_arg(ap, uintmax_t);
	else if (mem == 14)
		*((size_t *)variable) = va_arg(ap, size_t);
	return (variable);
}

static void		*selector(int mem, va_list ap)
{
	void *variable;

	if (!(variable = ft_memalloc(size(mem))))
		return (NULL);
	if (mem > 7)
		return (selector2(mem, ap, variable));
	if (mem == 1)
		*((unsigned char *)variable) = va_arg(ap, int);
	else if (mem == 2)
		*((signed char *)variable) = va_arg(ap, int);
	else if (mem == 3)
		*((short *)variable) = va_arg(ap, int);
	else if (mem == 4)
		*((unsigned short *)variable) = va_arg(ap, int);
	else if (mem == 5)
		*((int *)variable) = va_arg(ap, int);
	else if (mem == 6)
		*((unsigned int *)variable) = va_arg(ap, unsigned int);
	else if (mem == 7)
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
