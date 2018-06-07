#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char f[10] = {1, 3, 5, 7, 10, 48};
	ft_printf("\n%r\n",f);
//	printf("\n%g\n",f);
//	2.147484e+09
}
