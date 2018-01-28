/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:19:59 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/28 21:23:29 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_n_type(char *comm, va_list ap, va_list ap2, char *str_mom)
{
	void *container;

	container = ft_locate_pointer(comm, ap, ap2);
	if (!container)
		return (ft_strnew(1));
	if (ft_strstr(comm, "ll"))
		*((long long *)(container)) = ft_strlen(str_mom);
	else if (ft_strstr(comm, "l"))
		*((long *)(container)) = ft_strlen(str_mom);
	else if (ft_strstr(comm, "hh"))
		*((signed char *)(container)) = ft_strlen(str_mom);
	else if (ft_strstr(comm, "h"))
		*((short *)(container)) = ft_strlen(str_mom);
	else if (ft_strstr(comm, "z"))
		*((size_t *)(container)) = ft_strlen(str_mom);
	else if (ft_strstr(comm, "j"))
		*((intmax_t *)(container)) = ft_strlen(str_mom);
	else
		*((int *)(container)) = ft_strlen(str_mom);
	return (ft_strnew(1));
}
