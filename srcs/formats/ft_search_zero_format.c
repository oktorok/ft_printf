/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 02:47:28 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/07 02:49:27 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_search_zero(char * comm)
{
    while (*command)
    {   
        if (ft_isdigit(*command) && *command != '0')
            return (0);
        if (*command == '0')
        {
            while (*command)
                if (*command++ == '.')
                    return (variable);
            return (1);
        }
        command++;
    }   
    return (0);

}
