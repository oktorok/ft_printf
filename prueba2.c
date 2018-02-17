/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:56:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/17 20:41:28 by mrodrigu         ###   ########.fr       */
/*   Updated: 2018/02/17 04:37:10 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
int main(void)
{
	wchar_t s[4];
	s[0] = 0x53;
	s[1] = 0xd800;
	s[2] = 0x81000;
	s[3] = '\0';
	setlocale(LC_ALL,"");
	ft_putnbr(ft_printf("{%.5g}\n",1129.999999999999999));
	ft_putnbr(printf("{%.4g}\n", 1129.9999999999999999));
//	printf("%1$2$3$5$d",1,2,3,4,5);
  return (0);
}
