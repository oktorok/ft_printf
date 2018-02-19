#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>
int	main(void)
{
	ft_printf("%zu, %zu\n", (size_t)0, (size_t)ULLONG_MAX);
	printf("%zu, %zu\n", (size_t)0, (size_t)ULLONG_MAX);
}
