/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajust_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 06:58:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 12:56:14 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ajust_num_hex_oct_bin(int *siz_cuant, char *variable)
{
	int len;
	int	neg;

	neg = 0;
	if (*variable == '-')
		neg = 1;
	if (!siz_cuant[1] && *variable == '0')
		*variable = '\0';
	len = ft_strlen(variable);
	siz_cuant[0] = siz_cuant[0] > siz_cuant[1] ? siz_cuant[0] : siz_cuant[1] + neg;
	if (siz_cuant[0] < len)
		siz_cuant[0] = len;
	if (siz_cuant[1] >= 0)
	{
		if (siz_cuant[1] <= len - neg)
			siz_cuant[1] = len - neg;
	}
	return ;
}

static void ajust_float(int *siz_cuant, char *variab)
{
    int exp;

    exp = ft_atoi(ft_strchr(variab, 'e') + 2);
    if (siz_cuant[1] > 0)
        siz_cuant[1]++;
    if (siz_cuant[1] < 0)
        siz_cuant[1] = 7;
    if (exp > 16)
        siz_cuant[0] = siz_cuant[1] + 1;
    else if (siz_cuant[0] < 17 - exp + siz_cuant[1])
        siz_cuant[0] = 17 - exp + siz_cuant[1];
	return ;
}

static void ajust_char_string(int *siz_cuant, char *variable, int type)
{
    int len;

    len = ft_strlen(variable);
    if (siz_cuant[1] > len || siz_cuant[1] < 0)
        siz_cuant[1] = len;
    if ((!siz_cuant[0] || siz_cuant[0] < siz_cuant[1]) && siz_cuant[1])
        siz_cuant[0] = siz_cuant[1];
    if (!*variable && type == 'C')
    {
        if (!siz_cuant[0])
            siz_cuant[0] = 1;
        siz_cuant[1] = 1;
    }
}

void	ft_ajust_params(int *siz_cuant, char *variable, char *comm)
{
	int t;

	t = ft_toupper(comm[ft_strlen(comm) - 1]);

	if (t == 'D' || t == 'X' || t == 'B' || t == 'O' || t == 'U' || t == 'I')
		return (ajust_num_hex_oct_bin(siz_cuant, variable));
	else if (t == 'F' || t == 'G' || t == 'E')
		return (ajust_float(siz_cuant, variable));
	else if (t == 'C' || t == 'S')
		return (ajust_char_string(siz_cuant, variable, t));
	return ;
}
