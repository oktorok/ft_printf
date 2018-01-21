/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/21 03:29:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include "types.h"
# include "mods.h"
# include "formats.h"
# include "utils.h"

static const char	g_types[26] = {"sScCioOuUxXeEfFgGaAnbrk"};
static const char	g_length_modifiers[6][8] = {{"di"},{"ouxX"},{"n"},{"aAeEfFgG"},{"cs"}};
static char		*(*type_function [5])(char *, va_list, va_list) = {ft_s_type, ft_ws_type, ft_c_type, ft_wc_type, ft_i_type};
static void		*(*l_mods[1])(va_list, va_list, int *, char *) = {ft_wchar};
static const char   mods[7][2] = {"l", "hh", "h", "j", "z", "L"};
static void		*(*mod_selector[1][1])(va_list, va_list, int *, char *) = {{ft_wchar}};
//char			*ft_s_type(char *str, va_list ap);
//char			*ft_ws_type(char *str, va_list ap);
//char			*ft_c_type(char *str, va_list ap);
//char			*ft_wc_type(char *str, va_list ap);
//void			*ft_wchar(void *variable, int *siz_cuant, char *command);
//char			*ft_utf8(wchar_t num);
//void			ft_field_format(int *size_cuant, char *command, char *variable);
//void			*ft_l_mod(int *siz_cuant, char *command, void *variable);
//int			ft_minus_format(char *command);
char			*ft_realloc_printf(char *, char *, char *);
int				ft_printf(const char *str, ...);
#endif
