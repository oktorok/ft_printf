/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:56:49 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/14 06:31:57 by jagarcia         ###   ########.fr       */
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
//	printf("%*1$--*1$#*1$ld", 7, 6);
	char *comm = ft_transcomm("%****d");
	ft_putstr(comm);

  return (0);
}
