/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:01:53 by jagarcia          #+#    #+#             */
/*   Updated: 2017/11/10 22:22:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*dstcp;
	const char	*srccp;

	dstcp = (char *)dst;
	srccp = (const char *)src;
	if (n != 0)
	{
		while (n > 0)
		{
			*dstcp = *srccp;
			dstcp++;
			srccp++;
			n--;
		}
	}
	return (dst);
}
