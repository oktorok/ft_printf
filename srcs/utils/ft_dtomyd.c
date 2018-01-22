/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtomyd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 01:24:44 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 04:02:05 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_myfloat	ft_dtomyd(unsigned long int d)
{
	t_myfloat	n;

	/*moviendo 11 a la izquierda colocas la mantissa 
	en la posicion 63, la posicion 64 es para el 1 implicito 
	en la mantissa que se coloca con la puerta or ('|') y la mascara*/
	n.mantissa = ((d << 11) | 0x8000000000000000) >> 11;
	/*movemos 1 a la izquierda para quitarse el valor del bit de signo,
	32 a la iquierda para movel el exponente a la posicion 32 para que
	quepa en un int y despues aplicamos la mascara para eliminar los
	posibles valores que queden de la mantissa*/
	n.exponent = ((d << 1) >> 53) - 1075;
	return (n);
}
