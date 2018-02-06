/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:19:59 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 04:34:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_n_type(char *comm, va_list ap, va_list ap2, size_t len)
{
	void *container;

	container = ft_locate_pointer(comm, ap, ap2);
	if (!container)
		return ;
	if (ft_strstr(comm, "ll"))
		*((long long *)(container)) = len;
	else if (ft_strstr(comm, "l"))
		*((long *)(container)) = len;
	else if (ft_strstr(comm, "hh"))
		*((signed char *)(container)) = len;
	else if (ft_strstr(comm, "h"))
		*((short *)(container)) = len;
	else if (ft_strstr(comm, "z"))
		*((size_t *)(container)) = len;
	else if (ft_strstr(comm, "j"))
		*((intmax_t *)(container)) = len;
	else
		*((int *)(container)) = len;
}
