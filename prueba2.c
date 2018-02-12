#include"libftprintf.h"
#include<stdio.h>
int main(void)
{
	int T;
	char *caca = 0;
 T = printf("{%s}\n",caca);
 ft_putnbr(T);
T=  ft_printf("{%s}\n", caca);
 ft_putnbr(T);
  return (0);
}
