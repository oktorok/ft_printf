/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:45:26 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/17 08:31:48 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
#define FORMATS_H

void			ft_field_format(int *size_cuant, char *command, char *variable);
int				ft_minus_format(char *command);
char			*ft_space_format(char *command, char *variable);
char			*ft_plus_format(char *command, char *variable);

#endif
