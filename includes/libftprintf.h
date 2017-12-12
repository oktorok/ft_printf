/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/11 21:25:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

static const char g_types[14][4] = {{"sS"}, {"p"}, {"dDi"}, {"oO"},
	{"uU"}, {"xX"}, {"cC"}, {"eE"},
	{"fF"}, {"gG"}, {"aA"}, {"n"},
	{"brk"}};

int		ft_s_func(void **fin, char *str, va_list ap);
void	ft_field_func(int *size_cuant, char **command);
t_list	*ft_realloc_printf(t_list **dst, void *src, int content_size);
int		ft_printf(const char *str, ...);
static int (*type_function [1])(void **, char *, va_list) = {ft_s_func};
#endif
