#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
//	char f[10] = {1, 3, 5, 7, 10, 48};
	ft_printf("\n%2$s, %1$s, %3$i, %5$*3$c, %2$s, %4$.*3$s\n","1 arg", "2 arg", 3, "4 arg", '5');
	printf("\n%2$s, %1$s, %3$i, %5$*3$c, %2$s, %4$.*3$s\n","1 arg", "2 arg", 3, "4 arg", '5');
//	printf("\n%g\n",f);
//	2.147484e+09
}
