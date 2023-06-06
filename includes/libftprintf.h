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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# include "types.h"
# include "mods.h"
# include "formats.h"
# include "utils.h"

static const char	g_types[25] = {"%sScCidDoOuUxXpbrfFeEgGnm"};
extern	int			((*g_type_func[25])(char *a, va_list *b,
						char **c, size_t d));
static const char	g_mods[6][3] = {"h", "hh", "ll", "l", "z", "j"};
extern const char	*g_format;

extern	char		(*(*g_mod_selector[7])(va_list *a, va_list *b, char *c));
int					ft_printf(const char *str, ...);
int					ft_asprintf(char **buffer, const char *str, ...);
int					ft_dprintf(int fd, const char *str, ...);
#endif
