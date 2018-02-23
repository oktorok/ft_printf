#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("\n%e\n",1e-300);
	printf("%e\n",1e-300);
//	2.147484e+09
}
