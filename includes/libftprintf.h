/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/17 02:47:22 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

static const char	g_types[26] = {"sScCpdDioOuUxXeEfFgGaAnbrk"};
static const char	g_length_modifiers[6][8] = {{"di"},{"ouxX"},{"n"},{"aAeEfFgG"},{"cs"}};

char			*ft_s_func(char *str, va_list ap);
char			*ft_ws_func(char *str, va_list ap);
char			*ft_c_func(char *str, va_list ap);
char			*ft_wc_func(char *str, va_list ap);
void			*ft_wchartype(void *variable, int *siz_cuant, char *command);
char			*ft_utf_8(wchar_t num);
void			ft_field_func(int *size_cuant, char *command, char *variable);
void			*ft_l_func(int *siz_cuant, char *command, void *variable);
int				ft_minus_func(char *command);
char			*ft_realloc_printf(char *, char *, char *);
int				ft_printf(const char *str, ...);
static char		*(*type_function [4])(char *, va_list) = {ft_s_func, ft_ws_func, ft_c_func, ft_wc_func};
static void		*(*mod_func[1])(void *, int *, char *) = {ft_wchartype};
#endif
