/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:11:20 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 16:24:10 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERN_H
# define EXTERN_H

int				(*g_type_func[25])(char *, va_list *, char **, size_t len) = {
	ft_percent_type, ft_sls_type, ft_sls_type, ft_clc_type, ft_clc_type,
	ft_ilidld_type, ft_ilidld_type,
	ft_ilidld_type, ft_oloulu_type, ft_oloulu_type, ft_oloulu_type,
	ft_oloulu_type, ft_xlx_type, ft_xlx_type, ft_p_type, ft_b_type,
	ft_r_type, ft_feleglg_type, ft_feleglg_type, ft_feleglg_type,
	ft_feleglg_type, ft_feleglg_type, ft_feleglg_type, ft_n_type, ft_m_type};

char			*(*g_mod_selector[7])(va_list *, va_list *, char *) =
{ft_none_mod, ft_h_mod, ft_hh_mod, ft_ll_mod, ft_l_mod, ft_z_mod, ft_j_mod};
const char		*g_format = "-+ 0'#*.";
#endif
