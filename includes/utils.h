/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:51:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/21 18:34:06 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "my_float.h"

void	*ft_wchar(va_list ap, va_list ap2, int *siz_cuant, char *command);
char	*ft_utf8(wchar_t num);
void	*ft_locate_pointer(char *comm, va_list ap, va_list ap2);
void	*ft_locate_date(char *comm, int mem, va_list ap, va_list ap2);

#endif
