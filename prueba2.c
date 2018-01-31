/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/31 22:22:44 by jagarcia         ###   ########.fr       */
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
wchar_t *a = L"sdfsdf";
char *h = "una frase";
void *caca = &Mul;
int *bobo;
short Ms = 32767;
short ms = -32768;
long gh = -1;
double d = 9.99999999;
char g = 1;
int T;
//ft_printf("grisu es: %s\n", ft_grisu(&d));

ft_putstr("MIO: \n");
T=ft_printf("<%.0d>\n<%+.i>\n<%   .0D>", 0, 0, 0);
ft_putchar('\n');
ft_putnbr(T);
//ft_putnbr(*bobo);

printf("\nREAL: \n");
T=printf("<%.0d>\n<%+.i>\n<%   .0D>", 3, 0, 0);;
ft_putnbr(T);
ft_putchar('\n');
//ft_putnbr(*bobo);
} 
