/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 02:12:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void *typewchar(va_list ap, int *siz_cuant, char *command)
{
	wchar_t		*wvariable;
	char		*res;
	int			i;

	i = -1;
	wvariable = va_arg(ap, wchar_t *);
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
		siz_cuant[1] += ft_strlen(ft_utf_8(wvariable[i]));
		if (siz_cuant[1] > ft_atoi(command + 1))
		{
			siz_cuant[1] -= ft_strlen(ft_utf_8(wvariable[i]));
			break ;
		}
		i++;
	}
	return ((void *)res);		
}

void	*ft_l_func(int *siz_cuant, char *command, va_list ap)
{
	int		i;
	int		j;
	int		k;
	void	*(*mod_func[1])(va_list, int *, char *) = {typewchar};

	k = 0;
	while (command[k] != 'l' && command[k])
		k++;
	j = 0;
	while (g_length_modifiers[j] && (command[k] == 'l' && command[k + 1] != 'l'))
	{
		i = 0;
		while (g_length_modifiers[i][j])
		{
			if (command[k + 1] == g_length_modifiers[i][j])
				return ((mod_func[0])(ap, siz_cuant, command));
			i++;
		}
		j++;
	}
	return (NULL);
}
