/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:49:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/02 03:14:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

char			*ft_percent_type(char *str, va_list ap, va_list ap2);
char			*ft_sls_type(char *str, va_list ap, va_list ap2);
char			*ft_ws_type(char *str, va_list ap, va_list ap2);
char			*ft_clc_type(char *str, va_list ap, va_list ap2);
char			*ft_wc_type(char *str, va_list ap, va_list ap2);
char			*ft_ilidld_type(char *str, va_list ap, va_list ap2);
char			*ft_li_type(char *str, va_list ap, va_list ap2);
char			*ft_oloulu_type(char *str, va_list ap, va_list ap2);
char			*ft_xlx_type(char *str, va_list ap, va_list ap2);
char			*ft_p_type(char *str, va_list ap, va_list ap2);
char			*ft_n_type(char *str, va_list ap, va_list ap2, char *str_mom);
char			*ft_e_type(char *comm, va_list ap, va_list ap2);
char			*ft_b_type(char *comm, va_list ap, va_list ap2);
char			*ft_r_type(char *comm, va_list ap, va_list ap2);

#endif
