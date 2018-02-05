/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:49:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/05 06:27:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

static const char	g_symbols[33][6] = {"[NUL]", "[SOH]", "[STX]", "[ETX]", "[EOT]",
		"[ENQ]", "[ACK]", "[BEL]", "[BS]", "[HT]", "[NL]", "[VT]", "[NP]",
		"[CR]", "[SO]", "[SI]", "[DLE]", "[DC1]", "[DC2]", "[DC3]",
		"[DC4]", "[NAK]", "[SYN]", "[ETB]", "[CAN]", "[EM]", "[SUB]",
		"[ESC]", "[FS]", "[GS]", "[RS]", "[US]", "[SP]"};

int			ft_percent_type(char *str, va_list ap, va_list ap2, char **res);
int			ft_sls_type(char *str, va_list ap, va_list ap2, char **res);
int			ft_clc_type(char *str, va_list ap, va_list ap2, char **res);
int			ft_ilidld_type(char *str, va_list ap, va_list ap2, char **res);
int			ft_oloulu_type(char *str, va_list ap, va_list ap2, char **res);
int			ft_xlx_type(char *str, va_list ap, va_list ap2, char **res);
int			ft_p_type(char *str, va_list ap, va_list ap2, char **res);
char		*ft_n_type(char *str, va_list ap, va_list ap2, char *str_mom);
//int			*ft_e_type(char *comm, va_list ap, va_list ap2, char **res);
int			ft_b_type(char *comm, va_list ap, va_list ap2, char **res);
int			ft_r_type(char *comm, va_list ap, va_list ap2, char **res);

#endif
