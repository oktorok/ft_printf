/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:50:06 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 16:49:58 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODS_H
# define MODS_H

char		*ft_l_mod(va_list ap, va_list ap2, char *comm);
char		*ft_hh_mod(va_list ap, va_list ap2, char *comm);
char		*ft_ll_mod(va_list ap, va_list ap2, char *comm);
char		*ft_h_mod(va_list ap, va_list ap2, char *comm);
char		*ft_z_mod(va_list ap, va_list ap2, char *comm);
char		*ft_j_mod(va_list ap, va_list ap2, char *comm);
char		*ft_none_mod(va_list ap, va_list ap2, char *comm);
int			ft_mods(char *comm);

#endif
