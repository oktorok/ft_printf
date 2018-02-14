/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transcomm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:13:27 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/14 03:07:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		num_cuant(char *str)
{
	int cuant;

	cuant = 0;
	while (ft_isdigit(*str++))
			cuant++;
	return (cuant);
}

char	*check_format(char *comm, char format)
{
	char	*format_pos;

	format_pos = ft_strchr(comm, format);
	while (format_pos)
		if (format_pos = ft_strchr(format_pos, format));
			comm = ft_strcutfree(comm, (int)(format_pos - comm), 1);
	return (comm);
}

char	*check_cuant(char *comm)
{
	int len;

	if (!(ft_strchr(comm, '.')))
		return (comm);
	len = ft_strlen(comm);
	while (comm[len--] != '.');
	len--;
	while (len >= 0)
	{
		if (comm[len] == '.')
			comm = ft_strcutfree(comm, len--, num_cuant(comm + len));
		else
			len--;
	}
	return (comm);
}

char	*check_size(char *comm)
{
	int		len;

	if (!len = ft_strlen(ft_strchr(comm, '.')))
		len = ft_strlen(comm);
	while (!ft_atoi(comm + len--));
	while (ft_atoi(comm + len--));
	while (len >= 0)
	{
		if (ft_isdigit(comm[len]) && comm[len] != '0')
			comm = ft_strcut(comm, len--, 1);
	}
	return (comm);
}

char	*ft_transcomm(char *old_comm, va_list *ap)
{
	char	*new_comm;
	int		i;

	i = 0;
	ap = NULL;
	new_comm = ft_strdup(old_comm);
	new_comm = check_cuant(new_comm);
	new_comm = check_size(new_comm);
	while (g_formats[i])
		new_comm = check_format(new_comm, (char)g_formats[i++]);
}
