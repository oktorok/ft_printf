/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/16 02:18:52 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

static const char g_types[26] = {"sSpdDioOuUxXcCeEfFgGaAnbrk"};
static const char g_length_modifiers[6][8] = {{"di"},{"ouxX"},{"n"},{"aAeEfFgG"},{"cs"}};

char			*ft_s_func(char *str, va_list ap);
char			*ft_utf_8(wchar_t num);
void			ft_field_func(int *size_cuant, char *command, char *variable);
void			*ft_l_func(int *siz_cuant, char *command, va_list ap);
int				ft_minus_func(char *command);
char			*ft_realloc_printf(char *, char *, char *);
int				ft_printf(const char *str, ...);
static char		*(*type_function [1])(char *, va_list) = {ft_s_func};
#endif
