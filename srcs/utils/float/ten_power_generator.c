/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_power_generator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:01:18 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/01/19 18:24:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	int		i;
	int		j;

	fd = open("../../../includes/ten_power.h", O_RDWR);
	i = 1;
	dprintf(fd, "#ifndef TEN_POWER_H\n# define TEN_POWER_H\n\nstatic const double g_ten_powers[69] = {\n");
	while (i <= 69)
	{
		j = 0;
		dprintf(fd,"\t1");
		while (j < i)
		{
			dprintf(fd, "0");
//			if (!(j % 70) && j != 0)
//				dprintf(fd, "\n\t");
			j++;
		}
		dprintf(fd, ".00000,\n");
		i++;
	}
	dprintf(fd, "};\n#endif");
	return (0);
}
