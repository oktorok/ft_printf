/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:50:06 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/23 03:43:54 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODS_H
#define MODS_H

void		*ft_l_mod(int *siz_cuant, char *command, va_list ap, va_list ap2);
int			ft_mods(char *comm);
void		*ft_long(va_list ap, va_list ap2, char *comm);
void		*ft_longlong(va_list ap, va_list ap2, char *comm);
void		*ft_ulong(va_list ap, va_list ap2, char *comm);
void		*ft_ullong(va_list ap, va_list ap2, char *comm);
void		*ft_int(va_list ap, va_list ap2, char *comm);
void		*ft_intmax(va_list ap, va_list ap2, char *comm);
void		*ft_signed_char(va_list ap, va_list ap2, char *comm);
void		*ft_short(va_list ap, va_list ap2, char *comm);
void		*ft_sizet(va_list ap, va_list ap2, char *comm);
void		*ft_uioctal(va_list ap, va_list ap2, char *comm);
void		*ft_uloctal(va_list ap, va_list ap2, char *comm);
void		*ft_ulloctal(va_list ap, va_list ap2, char *comm);

#endif
