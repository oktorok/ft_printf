/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:56:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/14 01:26:01 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>
int	main(void)
{
	setlocale(LC_ALL,"");
//	ft_printf("{%03c}", 0);
//	printf("%.20 ' 30ld", 111111123567)
	ft_transcomm("%000d", NULL);

  return (0);
}
