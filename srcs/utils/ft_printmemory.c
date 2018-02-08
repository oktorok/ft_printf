/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 04:01:34 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/08 15:35:47 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

#define L_ENDIAN_H "=================LITTLE ENDIAN=================\n\n"
#define B_ENDIAN_H "===================BIG ENDIAN==================\n\n"

static void	ft_printbyte(size_t j, char **aux)
{
	ft_sprintf(*aux, " Byte %lu     ", j + 1);
	(*aux) += 12;	
}

static void	ft_printhex(char *n, char **aux, size_t j)
{
	ft_sprintf(*aux, "  %x    %x  |  ", (n[j] & 0xF0) >> 4, n[j] & 0xF);
	(*aux) += 12;
}

static void	ft_printbin(char *n, char **aux, size_t j)
{
	char	*bin;
	char	num;
	
	ft_strcpy(*aux, "0000 0000 | ");
	num = (n[j] & 0xF0) >> 4;
	bin = ft_dectobin(&num, 1);
	ft_strncpy((*aux) + 4 - ft_strlen(bin), bin, ft_strlen(bin));
	ft_strdel(&bin);
	num = n[j] & 0xF;
	bin = ft_dectobin(&num, 1);
	ft_strncpy((*aux) + 9 - ft_strlen(bin), bin, ft_strlen(bin));
	ft_strdel(&bin);
	(*aux) += 12;
}

static void	ft_print_littleendian(char *n, size_t len, char *str)
{
	size_t	i;
	size_t	j;
	char	*aux;
	
	i = 0;
	aux = str;
	ft_strcpy(aux, L_ENDIAN_H);
	aux += 49;
	while (i < len)
	{
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
			ft_printbyte(j++, &aux);
		ft_memset(aux++, '\n', 1);
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
			ft_printhex(n, &aux, j++);
		ft_memset(aux++, '\n', 1);
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
			ft_printbin(n, &aux, j++);
		ft_memset(aux++, '\n', 1);
		j = i;
		while (((j % 4) || (j == i)) && (j < len))
		{
			ft_strcpy(aux, "------------");
			aux += 12;
			j++;
		}
		ft_memset(aux++, '\n', 1);
		i += (j - i);
	}
}

char		*ft_printmemory(void *mem, size_t len)
{
	char	*n;
	char	*str;
	size_t	i;

	i = 0;
	n = (char *)mem;
	str = ft_strnew(98 + (len * 48) + (len / 4) + ((len % 4) ? 1 : 0));
	ft_print_littleendian(n, len, str);
//	ft_print_bigendian(n, len, str);
	return (str);
}
