#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int	main(void)
{
	size_t a = ULLONG_MAX;
	size_t b = 0;

	printf("{%f}\n", -556534656556454645.42);
	ft_printf("{%f}\n", -556534656556454645.42);
}
