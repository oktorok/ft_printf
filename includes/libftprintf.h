/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/08 00:00:51 by jagarcia         ###   ########.fr       */
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

char	*ft_sS_func(char *str);
char	*ft_realloc_printf(char *dst, char *src);
int		ft_printf(const char *str, ...);
static char *(*type_function [1])(char *) = {ft_sS_func};
#endif
