/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:56:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/16 23:25:33 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>
int main(void)
{
	wchar_t s[4];
	char	*a;
	s[0] = 0x53;
	s[1] = 0xd800;
	s[2] = 0x81000;
	s[3] = '\0';
	a = (char *)(s + 1);
	setlocale(LC_ALL,"");
//	ft_putnbr(ft_printf("<%*.*d>", 0, 3, 0));
	ft_putnbr(printf("<%4.-10d>", 5, 3, 0));
//	printf("%1$2$3$5$d",1,2,3,4,5);
  return (0);
}
