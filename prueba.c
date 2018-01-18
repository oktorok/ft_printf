/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/18 22:17:56 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>

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
ft_putstr("MIO: \n");
ft_printf("ERES UNA <%*3$.*s>%*s,%2$.*5$s PUTA", 2,"pene",6 ,"caca", 3);
printf("\nREAL: \n");
printf("ERES UNA <%*3$.*s>%*s,%2$.*5$s PUTA", 2,"pene",6 ,"caca", 3);

//ft_printf("ERES UNA <%2$.*5$s> PUTA", 2,"pene",6 ,"caca", 3);
}
