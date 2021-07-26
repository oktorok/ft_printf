/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 05:20:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/23 17:59:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*for_e(char *str, int *siz_cuant)
{
	char	*new;
	char	*aux;
	int		len;

	len = (ft_strchr(str, 'e') - str - 1) + ft_atoi(ft_strchr(str, 'e') + 1);
	new = ft_memset(ft_strnew(siz_cuant[1] + 5), '0', siz_cuant[1] + 5);
	if (!new)
		return (NULL);
	new[0] = str[0];
	if (siz_cuant[1])
	{
		new[1] = '.';
		ft_strncpy(new + 2, str + 1, siz_cuant[1] - 1);
	}
	new[siz_cuant[1] + 1] = 'e';
	new[siz_cuant[1] + 2] = '+';
	if (len < 0)
		new[siz_cuant[1] + 2] = '-';
	aux = ft_itoa(ft_abs(len));
	if (ft_abs(len) > 9)
		ft_strcpy(new + 3 + siz_cuant[1], aux);
	else
		ft_strcpy(new + 4 + siz_cuant[1], aux);
	ft_strdel(&aux);
	return (new);
}

static char	*for_g_f(char *str, int *siz_cuant, int len, char *comm)
{
	char	*new;

	new = for_f(str, siz_cuant);
	if (!new)
		return (NULL);
	if (ft_strchr(comm, '#'))
		return (new);
	if (ft_strchr(new, '.') - new >= siz_cuant[1])
		new = ft_strcutfree(new, siz_cuant[1], ft_strlen(new));
	else
	{
		if (siz_cuant[0] < ++siz_cuant[1])
			siz_cuant[0] = siz_cuant[1];
	}
	len = ft_strlen(new) - 1;
	while (len >= 0 && (new[len] == '0' || new[len] == '.'))
	{
		if (len < siz_cuant[0])
			siz_cuant[0]--;
		if (new[len] == '.')
			return (ft_memset(new + len, 0, 1) - len);
		else
			new[len--] = 0;
	}
	return (new);
}

static char	*for_g_e(char *str, int *siz_cuant, int len, char *comm)
{
	char	*new;
	char	*aux;

	new = for_e(str, siz_cuant);
	if (!new)
		return (NULL);
	if (siz_cuant[1] == 1)
		siz_cuant[0]--;
	if (ft_strchr(comm, '#'))
		return (new);
	len = ft_strchr(new, 'e') - new - 1;
	while (len >= 0 && (new[len] == '0' || new[len] == '.'))
		len--;
	aux = ft_strncpy(ft_strnew(len + 5), new, len + 1);
	if (!aux)
		return (NULL);
	ft_strcpy(aux + (len + 1), ft_strchr(new, 'e'));
	ft_strdel(&new);
	return (aux);
}

char	*ft_putthepoint(char *str, int *siz_cuant, char *comm)
{
	char	type;
	char	neg;
	char	*aux;
	int		len;

	neg = 0;
	if (*str == '-')
		neg = 1;
	type = ft_toupper(comm[ft_strlen(comm) - 1]);
	len = (ft_strchr(str, 'e') - str) + ft_atoi(ft_strchr(str, 'e') + 1);
	if (type == 'F')
		aux = for_f(str + neg, siz_cuant);
	else if (type == 'E')
		aux = for_e(str + neg, siz_cuant);
	else if (len < -4 || len > siz_cuant[1])
		aux = for_g_e(str + neg, siz_cuant, len, comm);
	else
		aux = for_g_f(str + neg, siz_cuant, len, comm);
	ft_strdel(&str);
	if (neg && aux)
		aux = ft_strjoinfree(ft_strdup("-"), aux);
	if (siz_cuant[0] < (int)ft_strlen(aux))
		siz_cuant[0] = ft_strlen(aux);
	return (aux);
}
