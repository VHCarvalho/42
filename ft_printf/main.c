#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
	int ret;
	int *uns;

	&uns = 0;
	ret = ft_printf("Vamos a la %p\n", &uns);
	printf("%d\n", ret);
	ret = printf("Vamos a la %p\n", &uns);
	printf("%d\n", ret);
	return (0);
}
