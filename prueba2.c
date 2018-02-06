/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/06 04:50:31 by mrodrigu         ###   ########.fr       */
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
char str[] = "PU{red}TA";

#define red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define cyan  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
#define green "\033[9;38;5;198m"        /* 4 -> underline ;  32 -> green */
#define blue  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */
 
#define black  "\033[0;30m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"
 
#define none   "\033[0m"        /* to flush the previous property */

//printf("PUTA %s TU MADRE", green);


//ft_printf("grisu es: 1852827356%o\n", ft_grisu(&d));

//ft_putstr("MIO: \n");
//T=ft_printf("%8C et coco %    C titi %lc", 3250, 0x11ffff, 'a');

printf("<%s>", ft_colors(str, ft_strlen(str)));

//T = ft_printf("primero segundo %s cuarto quinto %s septimo",NULL, "sexto");

int *papa = (int *)malloc(8);
T= ft_printf("<este char es nulo (%c)>a\n",'\0');
ft_putnbr(T);
T= printf("<este char es nulo (%c)>a\n",'\0');

//ft_putnbr(T);
//ft_putnbr(*bobo);

//printf("\nREAL: \n");
//int jacobo = 0;
/*for (int i =100;i< 0;i++)
{
	T = sprintf(ft_strnew(5),"%C", 0x11ffff - i);
	if (T == -1)
		jacobo++;
}*/
//T = printf("%8C et coco %C titi %lc", 3250, 'a', 0x11ffff);
//ft_putnbr(T);
//ft_putchar('\n');
//ft_putnbr(*bobo);
} 
