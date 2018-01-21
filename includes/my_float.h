/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:41:29 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/21 21:24:21 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FLOAT_H
# define MY_FLOAT_H

# include "ten_power.h"

typedef struct			s_myfloat
{
	unsigned long int	mantissa;
	int					exponent;
}						t_myfloat;

void		grisu(double *d);
t_myfloat	ft_take_power(int k);
t_myfloat	ft_multiply(t_myfloat x, t_myfloat y);
t_myfloat	ft_dtomyd(unsigned long int l);
int			ft_choose_power(int e, int alpha);
double		ft_sige(double x);


#endif
