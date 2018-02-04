/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:48:09 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/04 02:14:28 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int 	ft_realloc_printf(char **final, char *str, char *com_res)
{
	char	*newres;
	int		len;

	len = 0;
	if (!com_res)
		newres = str;
	else
	{
		newres = ft_strjoin(str, com_res);
		ft_strdel(&com_res);
	}
	len = ft_strlen(newres);
	if (*final)
		*final = ft_strjoinfree(*final, newres);
	else
		*final = newres;
	return (len);
}


/*char	*ft_realloc_printf(char *s, char *start, char *end)
{
	char *str;
	
	if (!start)
	{
		ft_strdel(&s);
		return (NULL);
	}
	if (!end)
	{
		if (!(str = ft_strjoin(s, start)))
			return (NULL);
		ft_strdel(&s);
		return (str);
	}
	if (!(str = ft_strnjoin(s, start, (unsigned int)(end - start))))
		return (NULL);
	ft_strdel(&s);
	return (str);
}*/
