/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:51:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 18:03:06 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "my_float.h"

static const char	g_colors[8][10] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
static const char	g_formats[10][10] = {"normal", "bold", "fait", "italic", "underline", "sblink", "rblink", "reverse", "conceal", "crossed"};

char	*ft_wchar(va_list ap, va_list ap2, int *siz_cuant, char *command);
char	*ft_utf8(wchar_t num);
void	*ft_locate_pointer(char *comm, va_list ap, va_list ap2);
void	*ft_locate_date(char *comm, int mem, va_list ap, va_list ap2);
char	*ft_dectobin(void *num, size_t len);
char	*ft_dectooct(void *num, size_t len);
char	*ft_dectohex(void *num, size_t len);
char	*ft_printmemory(void *mem, size_t len);
char	*ft_colors(char *str, size_t len);

#endif
