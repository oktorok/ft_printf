/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:34:52 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/18 12:48:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char *buffer;
	char *frase;
	int numero;
	
	buffer = "%i, %2$.*1$s|\n";
	frase = "caca pedo pis";
	numero = 4;
	
	ft_putstr("PRINTF:\n");
	printf(buffer, numero, frase, numero + 5);
	ft_putstr("FT_PRINTF\n");
	ft_printf(buffer, numero, frase, numero + 5);
}
