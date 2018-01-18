/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:34:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/17 20:24:44 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_wchar(va_list ap, int *siz_cuant, char *command)
{
	wchar_t		*wvariable;
	char		*res;
	int			i;

	i = -1;
	wvariable = va_arg(ap, wchar_t *);
	//wvariable = ft_locate-variable(comm, ap, 4);
	res = ft_strnew(0);
	while (wvariable[++i])
		res = ft_strjoinfree(res, ft_utf8(wvariable[i]));
	i = 0;
	while (*command != '.' && *command)
		command++;
	if (!*command)
		siz_cuant[1] = ft_strlen(res);
	while (wvariable[i] && siz_cuant >= 0 && *command)
	{
		siz_cuant[1] += ft_strlen_free((ft_utf8(wvariable[i])));
		if (siz_cuant[1] > ft_atoi(command + 1))
		{
			siz_cuant[1] -= ft_strlen_free((ft_utf8(wvariable[i])));
			break ;
		}
		i++;
	}
	return ((void *)res);
}
