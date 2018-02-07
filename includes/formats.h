/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:45:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 07:33:59 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
#define FORMATS_H

void			ft_field_format(int *size_cuant, char *command, va_list ap, va_list ap2);
int				ft_minus_format(char *command);
char			*ft_space_format(char *command, char *variable, int *siz_cuant);
char			*ft_plus_format(char *command, char *variable, int *siz_cuant);
char			*ft_hash_format(char *command, char *variable, int *siz_cuant);
char    		*ft_apostrophe_format(char *comm, char *variable);
char			*ft_zero_format(char *comm, char *variable, int *siz_cuant);
int				ft_search_zero_format(char *command);

#endif
