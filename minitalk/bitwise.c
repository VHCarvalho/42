#include <stdio.h>

int main(void)
{
	char						c;
	unsigned int		nbr_c;
	unsigned int		nbr_p;
	char						p;
	int							i;

	i = 0;
	nbr_p = 0;
	c = 'c';
	nbr_c = c;
	printf("nbr_c: %d\n", nbr_c);
	while (i < 8)
	{
		nbr_p += (nbr_c % 2) << i;
		printf("nbr_p: %d\n", nbr_p);
		nbr_c = nbr_c >> 1;
		i++;
	}
	nbr_p += nbr_c % 2;
	printf("nbr_p: %d\n", nbr_p);
	p = nbr_p;
	printf("%c\n", p);

	return(0);
}
