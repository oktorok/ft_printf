/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:34:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2017/12/16 06:05:45 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_wchartype(void *variable, int *siz_cuant, char *command)
{
	wchar_t		*wvariable;
	char		*res;
	int			i;

	i = -1;
	wvariable = (wchar_t *)variable;
	res = ft_strnew(0);
	while (wvariable[++i])
		res = ft_strjoinfree(res, ft_utf_8(wvariable[i]));
	i = 0;
	while (*command != '.' && *command)
		command++;
	if (!*command)
		siz_cuant[1] = ft_strlen(res);
	while (wvariable[i] && siz_cuant >= 0 && *command)
	{
		siz_cuant[1] += ft_strlen_free((ft_utf_8(wvariable[i])));
		if (siz_cuant[1] > ft_atoi(command + 1))
		{
			siz_cuant[1] -= ft_strlen_free((ft_utf_8(wvariable[i])));
			break ;
		}
		i++;
	}
	return ((void *)res);
}
