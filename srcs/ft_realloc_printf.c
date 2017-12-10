/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:48:09 by jagarcia          #+#    #+#             */
/*   Updated: 2017/12/10 04:57:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_realloc_printf(t_list **dst, void *content, int content_size)
{
	if (!*dst)
	{
		if (!(*dst = ft_lstnew(content, content_size)))
			return (NULL);
		return (*dst);
	}
	if (!((*dst)->next = ft_lstnew(content, content_size)))
		return (NULL);
	return ((*dst)->next);
}
