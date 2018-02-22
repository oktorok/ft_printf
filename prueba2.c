#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int	main(void)
{
	size_t a = ULLONG_MAX;
	size_t b = 0;

	ft_printf("{%1$d,%2$d,%1$d}\n", 1, 2);
	printf("{%1$d,%2$d,%1$d}\n", 1, 2);
}
