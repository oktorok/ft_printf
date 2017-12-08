/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 21:52:57 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/08 05:05:43 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int		main(void)
{
	printf("El suyo: ERES UNA <%-20.5s> ESTUPIDA\n","MALDITA");
	ft_printf("El mio: ERES UNA <%-20.5s> ESTUPIDA", "MALDITA");
	return (0);
}
