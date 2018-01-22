/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:48:48 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/22 02:05:21 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

t_myfloat	ft_multiply(t_myfloat x, t_myfloat y)
{
	unsigned long int a,b,c,d,ac,bc,ad,bd,tmp;
  t_myfloat r; unsigned long int M32 = 0xFFFFFFFF;
  a = x.mantissa >> 32; b = x.mantissa & M32;
  c = y.mantissa >> 32; d = y.mantissa & M32;
  ac = a*c; bc = b*c; ad = a*d; bd = b*d;
  tmp = (bd>>32) + (ad&M32) + (bc&M32);
  tmp += 1U << 31; /// mult_round
  r.mantissa = ac+(ad>>32)+(bc>>32)+(tmp >>32);
  r.exponent = x.exponent + y.exponent + 64;
  return r;
}
