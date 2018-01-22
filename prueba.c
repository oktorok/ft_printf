/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 18:40:02 by mrodrigu         ###   ########.fr       */
/*   Updated: 2018/01/21 21:45:18 by mrodrigu         ###   ########.fr       */
/*   Updated: 2018/01/22 03:42:45 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

char	*ft_utf_8(wchar_t caca);

void print_bytes(void *ptr, int size) 
{
	unsigned char *p = ptr;
	int i;
	for (i=0; i<size; i++) {
		printf("%02hhX ", p[i]);
	}
	printf("\n");
}

int		main(void)
{
	setlocale(LC_ALL, "");
//	signed char a = 'a';
	unsigned int b = 2147;
ft_putstr("MIO: \n");
ft_printf("ERES UNA <%-10.6i> PUTA",b);

printf("\nREAL: \n");
printf("ERES UNA <%-10.6i> PUTA",b);
printf("<%i>\n",123123);
double u = -289.8918482441383782;
printf("sige: %f\nceil: %f\n", ft_sige(u), ceil(u));

double a = 13.18;
void *p = &a;
grisu((double *)p);
}
