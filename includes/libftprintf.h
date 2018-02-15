/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/16 00:38:51 by jagarcia         ###   ########.fr       */
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

static const char	g_types[25] = {"%sScCidDoOuUxXpbrfFeEgGnm"};
static int			(*g_type_func[24])(char *, va_list *, char **, size_t len) =
{ft_percent_type, ft_sls_type, ft_sls_type, ft_clc_type, ft_clc_type,
	ft_ilidld_type, ft_ilidld_type,
	ft_ilidld_type, ft_oloulu_type, ft_oloulu_type, ft_oloulu_type,
	ft_oloulu_type, ft_xlx_type, ft_xlx_type, ft_p_type, ft_b_type,
	ft_r_type, ft_feleglg_type, ft_feleglg_type, ft_feleglg_type,
 ft_feleglg_type, ft_feleglg_type, ft_feleglg_type, ft_m_type};
static const char	g_mods[6][3] = {"ll", "l", "hh", "h", "j", "z"};
static const char	*g_format = "-+ 0'#*.";
static char			*(*g_mod_selector[7])(va_list, va_list, char *) =
{ft_none_mod, ft_ll_mod, ft_l_mod, ft_hh_mod, ft_h_mod, ft_j_mod, ft_z_mod};
int					ft_printf(const char *str, ...);
int					ft_sprintf(char *buffer, const char *str, ...);
#endif
