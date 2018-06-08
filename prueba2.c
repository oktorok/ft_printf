#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
//	char f[10] = {1, 3, 5, 7, 10, 48};
	ft_printf("\n%5$c, %4$.*3$s, %2$*6$s, %1$*7$s\n","1 arg", "2 arg", 3, "4 arg", '5', 10 ,40);
	printf("\n%5$c, %4$.*3$s, %2$*6$s, %1$*7$s\n","1 arg", "2 arg", 3, "4 arg", '5', 10, 40);
//	printf("\n%g\n",f);
//	2.147484e+09
}
