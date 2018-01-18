/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:51:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/18 18:10:43 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

void	*ft_wchar(va_list ap, int *siz_cuant, char *command);
char	*ft_utf8(wchar_t num);
void	*ft_locate_variable(char *comm, va_list ap, va_list ap2);

#endif
