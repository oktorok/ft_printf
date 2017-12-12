/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/12/12 02:02:41 by mrodrigu         ###   ########.fr       */
=======
/*   Updated: 2017/12/11 21:40:28 by jagarcia         ###   ########.fr       */
>>>>>>> bf060ae127a50d10f93ec92637f8c4c56a027033
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
	char		*str;
	wchar_t		csa = L'\x64F0';
	str = ft_utf_8(csa);
	print_bytes(str, ft_strlen(str));
	ft_putstr(str);
//	wchar_t		*csa = L"\x9094E3";
//	void		*casa = csa;
//	char		*csa2 = (char *)csa;
//	int			*pe = (int *)malloc(8);
//	*pe = 42;
//	wchar_t		*csa3 = (wchar_t *)csa2;
//	char		csa4[3] = {0xC6,0x9B};
//	print_bytes(&csa,sizeof(wchar_t));
//	print_bytes(csa4, sizeof(char)*2);
//	write(1, &csa, sizeof(wchar_t));
//	write(1, (void*)pe, 8);

//	write(1, "\n", 1);
<<<<<<< HEAD
//	printf("%C",csa);
//	ft_printf("El mio: ERES UNA <%-20.5s> PUTA", "MALDITA");
=======
//	printf("%020i",1234567890);
	ft_printf("El mio: ERES UNA <%-20.5s> PUTA", "MALDITA");
>>>>>>> bf060ae127a50d10f93ec92637f8c4c56a027033
	return (0);
}
