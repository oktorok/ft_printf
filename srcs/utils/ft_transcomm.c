/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transcomm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:13:27 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/14 06:36:51 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		num_cuant(char *str)
{
	int cuant;

	cuant = 0;
	if (*str == '*')
		return (1);
	while (ft_isdigit(*str++))
			cuant++;
	return (cuant);
}

char	*check_format(char *comm, char format)
{
	char	*format_pos;
	int		flag;

	if (!(format_pos = ft_strchr(comm, format)))
		return (comm);
	format_pos = ft_strchr(format_pos + 1, format);
	while (format_pos)
	{
		flag = (int)(format_pos - comm);
		comm = ft_strcutfree(comm, flag, flag + 1);
		format_pos = ft_strchr(ft_strchr(comm, format) + 1, format);
	}
	return (comm);
}

char	*check_cuant(char **comm)
{
	int		len;
	char	*cuant;

	if (!(ft_strchr(*comm, '.')))
		return (NULL);
	len = ft_strlen(*comm) - 1;
	while (comm[0][len] != '.')
		len--;
	cuant = ft_strsub(*comm, len, num_cuant(*comm + len + 1) + 1);
	len = ft_strlen(*comm) - 1;
	while (len >= 0)
	{
		if (comm[0][len] == '.')
			*comm = ft_strcutfree(*comm, len, len + num_cuant(*comm + 1 + len) + 1);
		len--;
	}
	return (cuant);
}

char	*check_size(char **comm)
{
	int		len;
	char	*size;

	if (!(len = ft_strlen(ft_strchr(*comm, '.'))))
		len = ft_strlen(*comm) - 1;
	while ((!ft_atoi(*comm + len) && len >= 0) && comm[0][len] != '*')
		len--;
	while ((ft_atoi(*comm + len) && len >= 0) || comm[0][len] == '*')
		if (comm[0][--len + 1] == '*')
			break;
	if (comm[0][len] == '*')
		size = ft_strdup("*");
	else
		size = ft_itoa(ft_atoi(*comm + len + 1));
	len = ft_strlen(*comm) - 1;
	while (len >= 0)
	{
		if (comm[0][len] == '$' && len >= 0)
			while (ft_isdigit(comm[0][--len]));
		if (ft_isdigit(comm[0][len]) && comm[0][len] != '0')
			*comm = ft_strcut(*comm, len, len + 2);
		len--;
	}
	return (size);
}

char	*ft_transcomm(char *old_comm)
{
	char	*new_comm;
	char	*size_cuant;
	int		i;
	char	*tmp;

	i = 0;
	new_comm = ft_strdup(old_comm);
	tmp = check_cuant(&new_comm);
	size_cuant = ft_strjoinfree(check_size(&new_comm), tmp);
	while (g_format[i])
		new_comm = check_format(new_comm, (char)g_format[i++]);
	i = 0;
	while (i < 6)
	{
		if ((tmp = ft_strstr(new_comm, g_mods[i])))
		{
			new_comm = ft_strinsertfree(new_comm, size_cuant, (int)(tmp - new_comm - 1));
			break ;
		}
		i++;
	}
	if (i == 6)
		new_comm = ft_strinsertfree(new_comm, size_cuant, ft_strlen(new_comm) - 1);
	return (new_comm);
}
