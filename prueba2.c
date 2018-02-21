#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int	main(void)
{
	size_t a = ULLONG_MAX;
	size_t b = 0;

	ft_printf("{%.*5d}\n", -5, 42);
	printf("{%.*5d}\n", -5, 42);
}
