/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:45:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/18 18:10:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
#define FORMATS_H

void			ft_field_format(int *size_cuant, char *command, va_list ap, va_list ap2);
int				ft_minus_format(char *command);
char			*ft_space_format(char *command, char *variable);
char			*ft_plus_format(char *command, char *variable);

#endif
