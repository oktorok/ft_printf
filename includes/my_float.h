/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:41:29 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/21 18:57:49 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FLOAT_H
# define MY_FLOAT_H

# include "ten_power.h"

typedef struct			s_myfloat
{
	unsigned long int	mantissa;
	unsigned int		exponent;
}						t_myfloat;

t_myfloat	ft_dtomyd(unsigned long int l);
int			ft_choose_power(int e, int alpha);
double		ft_sige(double x);


#endif
