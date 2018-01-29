/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:49:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/29 22:28:32 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

char			*ft_s_type(char *str, va_list ap, va_list ap2);
char			*ft_ws_type(char *str, va_list ap, va_list ap2);
char			*ft_c_type(char *str, va_list ap, va_list ap2);
char			*ft_wc_type(char *str, va_list ap, va_list ap2);
char			*ft_id_type(char *str, va_list ap, va_list ap2);
char			*ft_li_type(char *str, va_list ap, va_list ap2);
char			*ft_ou_type(char *str, va_list ap, va_list ap2);
char			*ft_lolu_type(char *str, va_list ap, va_list ap2);
char			*ft_x_type(char *str, va_list ap, va_list ap2);
char			*ft_lx_type(char *str, va_list ap, va_list ap2);
char			*ft_p_type(char *str, va_list ap, va_list ap2);
char			*ft_n_type(char *str, va_list ap, va_list ap2, char *str_mom);
char			*ft_e_type(char *comm, va_list ap, va_list ap2);
char			*ft_b_type(char *comm, va_list ap, va_list ap2);

#endif
