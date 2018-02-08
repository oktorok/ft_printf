/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/08 08:57:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"
# include "types.h"
# include "mods.h"
# include "formats.h"
# include "utils.h"

static const char	g_types[27] = {"%sScCidDoOuUxXpbrneEfFgGaAk"};
static int		(*type_function [18])(char *, va_list *, char **, size_t len) =
{ft_percent_type, ft_sls_type, ft_sls_type, ft_clc_type, ft_clc_type, ft_ilidld_type, ft_ilidld_type,
	ft_ilidld_type, ft_oloulu_type, ft_oloulu_type, ft_oloulu_type, ft_oloulu_type,
 ft_xlx_type, ft_xlx_type, ft_p_type, ft_b_type, ft_r_type};
static const char   g_mods[8][3] = {"ll", "l","hh", "h", "j", "z"};
static char			*(*mod_selector[7])(va_list, va_list, char *) =
{ft_none_mod, ft_ll_mod, ft_l_mod, ft_hh_mod, ft_h_mod, ft_j_mod, ft_z_mod};

//char			*ft_realloc_printf(char *, char *, char *);
int				ft_realloc_printf(char **, char *, char *);
int				ft_printf(const char *str, ...);
int				ft_sprintf(char * buffer, const char *str, ...);
#endif
