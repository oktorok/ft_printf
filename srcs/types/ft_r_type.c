/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 22:09:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*non_printable(char *variable)
{
	char	symbols[33][6] = {"[NUL]" ,"[SOH]" ,"[STX]" ,"[ETX]" ,"[EOT]" ,
		"[ENQ]" ,"[ACK]" ,"[BEL]" ,"[BS]" ,"[HT]" ,"[NL]" ,"[VT]" ,"[NP]" ,
		"[CR]" ,"[SO]" ,"[SI]" ,"[DLE]" ,"[DC1]" ,"[DC2]" ,"[DC3]" ,
		"[DC4]" ,"[NAK]" ,"[SYN]" ,"[ETB]" ,"[CAN]" ,"[EM]" ,"[SUB]" ,
		"[ESC]" ,"[FS]" ,"[GS]" ,"[RS]" ,"[US]" ,"[SP]"};
	int		i;
	char	*new_variable;
	int		size;

	i = 0;
	size = 0;
	while (i < ft_strlen(variable) + 1)
		size += ft_strlen(symbols[variable[i++]]);
	ft_putnbr(size);
	new_variable = ft_strnew(size);
	i = 0;
	while (i < ft_strlen(variable) + 1)
	 	ft_strcat(new_variable, symbols[variable[i++]]);
	return(new_variable);
}

char			*ft_r_type(char *comm, va_list ap, va_list ap2)
{
	int		siz_cuant[2];
	char	*variable;
	char	*res;

	variable = (char *)ft_locate_pointer(comm, ap, ap2);
	variable = non_printable(variable);
	return (variable);
}
