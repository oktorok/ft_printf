/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/04 02:14:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

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
//wchar_t * a = L"\x3d5\x3d5\x3d6\xdf4";
long ml = -9223372036854775807 - 1;
long Ml = 9223372036854775807;
unsigned long Mul = 18446744073709551615U;
unsigned int Mui = 4294967295;
int Mi = 2147483647;
int mi = -2147483648;
wchar_t tyu = 0xbffe;
wchar_t a[4];
a[0] = 0x53;
a[1] = 0xd800;
a[2] = 0x81000;
a[3] = '\0';
void *caca = &Mul;
int *bobo;
short Ms = 32767;
short ms = -32768;
long gh = -1;
double d = 9.99999999;
char g = 1;
int T;
//ft_printf("grisu es: 1852827356%o\n", ft_grisu(&d));

ft_putstr("MIO: \n");
//T=ft_printf("%8C et coco %    C titi %lc", 3250, 0x11ffff, 'a');



T = ft_printf("primero segundo %s cuarto quinto %s septimo",NULL, "sexto");




ft_putnbr(T);
//ft_putnbr(*bobo);

printf("\nREAL: \n");
int jacobo = 0;
/*for (int i =100;i< 0;i++)
{
	T = sprintf(ft_strnew(5),"%C", 0x11ffff - i);
	if (T == -1)
		jacobo++;
}*/
//T = printf("%8C et coco %C titi %lc", 3250, 'a', 0x11ffff);
ft_putnbr(T);
ft_putchar('\n');
//ft_putnbr(*bobo);
} 
