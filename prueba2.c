#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	char *str = ft_memalloc(4);
	str[0] = 1;
	str[1] = 2;
	str[2] = 3;
	str[3] = 4;
	ft_printf("\n%r\n",str);
//	2.147484e+09
}
