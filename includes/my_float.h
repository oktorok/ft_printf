/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:41:29 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/26 19:17:23 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FLOAT_H
# define MY_FLOAT_H

# include "ten_power.h"

typedef struct s_myfloat
{
	unsigned long int	mantissa;
	int					exponent;
}						t_myfloat;

char					*ft_grisu(double *d);
t_myfloat				ft_take_power(int k);
t_myfloat				ft_multiply(t_myfloat x, t_myfloat y);
t_myfloat				ft_dtomyd(unsigned long int l);
int						ft_choose_power(int e, int alpha);
double					ft_sige(double x);
char					*ft_round(char *str, int pos, char *comm);
char					*ft_putthepoint(char *str, int *siz_cuant, char *comm);
char					*for_f(char *str, int *siz_cuant);

#endif
