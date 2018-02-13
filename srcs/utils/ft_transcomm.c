/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transcomm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:13:27 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/13 20:19:28 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*check_zeros(char *comm)
{
	char	*stop;
	int		i;
	char	*format_pos;

	i = -1;
	while (comm[++i])
		if ((ft_isdigit(comm[i]) && comm[i] != '0') || comm[i] == '.')
		{
			stop = comm + i;
			break ;
		}
	if (!comm[i])
		stop = comm + i;
	format_pos = ft_strchr(comm, '0');
	while (format_pos)
	{
		format_pos = ft_strchr(format_pos, '0');
		if (format_pos > stop)
			return (comm);
		comm = ft_strcutfree(comm, (int)(format_pos - comm), 1);
	}
	return (comm);
}

char	*ft_transcomm(char *str, va_list *ap, char *old_comm)
{
	char	*new_comm;
	char	*format_pos;
	int		del_pos;

	new_comm = ft_strdup(old_comm);
	while (*g_format)
	{
		if (*g_format == '0')
			new_comm = check_zeros(new_comm);
		else
		{
			format_pos = ft_strchr(new_comm, *g_format);
			if (format_pos = ft_strchr(format_pos, *g_format))
			{
				del_pos = format_pos - old_comm;
				new_comm = ft_strcutfree(new_comm, del_pos, del_pos + 1);
			}
			else
				g_format++;
		}
	}

}
