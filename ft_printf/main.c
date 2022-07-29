#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	int ret;
	char uns[] = "playa";

	ret = ft_printf("Vamos a la %s\n", uns);
	printf("%d\n", ret);
	ret = printf("Vamos a la %s\n", uns);
	printf("%d\n", ret);
	return (0);
}
