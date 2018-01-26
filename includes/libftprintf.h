/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/26 22:24:39 by mrodrigu         ###   ########.fr       */
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

static const char	g_types[26] = {"sScCidDoOuUxXpeEfFgGaAnbrk"};
static const char	g_length_modifiers[6][8] = {{"di"},{"ouxX"},{"n"},{"aAeEfFgG"},{"cs"}};
static char		*(*type_function [14])(char *, va_list, va_list) = {ft_s_type, ft_ws_type, ft_c_type, ft_wc_type, ft_id_type, ft_id_type, ft_li_type, ft_ou_type, ft_lolu_type, ft_ou_type, ft_lolu_type, ft_x_type, ft_lx_type, ft_p_type};
static const char   mods[8][3] = {"ll", "l","hh", "h", "j", "z"};
static void		*(*mod_selector[7][2])(va_list, va_list, char *) = 
{{ft_int, ft_uioctal},{ft_longlong,ft_ulloctal},{ft_long,ft_uloctal},{ft_signed_char},{ft_short},{ft_intmax},{ft_sizet}};
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
