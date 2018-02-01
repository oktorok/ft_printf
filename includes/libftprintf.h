/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/01 17:43:30 by jagarcia         ###   ########.fr       */
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

static const char	g_types[26] = {"sScCidDoOuUxXpebrEfFgGaAnk"};
static const char	g_length_modifiers[6][8] = {{"di"},{"ouxX"},{"n"},
	{"aAeEfFgG"},{"cs"}};
static char		*(*type_function [17])(char *, va_list, va_list) =
{ft_s_type, ft_ws_type, ft_c_type, ft_wc_type, ft_id_type, ft_id_type,
	ft_li_type, ft_ou_type, ft_lolu_type, ft_ou_type, ft_lolu_type,
 ft_x_type, ft_lx_type, ft_p_type, ft_e_type, ft_b_type, ft_r_type};
static const char   mods[8][3] = {"ll", "l","hh", "h", "j", "z"};
static char			*(*mod_selector[7])(va_list, va_list, char *) =
{ft_none_mod, ft_ll_mod, ft_l_mod, ft_hh_mod, ft_h_mod, ft_j_mod, ft_z_mod};
char			*ft_realloc_printf(char *, char *, char *);
int				ft_printf(const char *str, ...);
#endif
