/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/23 03:38:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>

char        *ft_alltoa_base(void *value, int base, size_t val_size, short unsig);
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
	signed char a = 'a';
	unsigned int b = 2147;
	int unsigned long c = 18446744073709551615;
	long long d =9223372036854775806;
ft_putstr("MIO: \n");
ft_printf("ERES UNA <%lli> PUTA",d);

printf("\nREAL: \n");
printf("ERES UNA <%lli> PUTA",d);

//double a = 13.18;
//void *p = &a;
//grisu((double *)p);
}
