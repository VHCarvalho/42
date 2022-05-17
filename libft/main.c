#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	s1[] = "lalaagula bonitalala";
	char	set[] = "la";
	char	*ret;

	ret = ft_strtrim(s1, set);

	printf("%s\n", ret);
	return (0);
}
