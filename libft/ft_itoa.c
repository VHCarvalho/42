/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:50:42 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/18 15:15:21 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	log_ten(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	i++;
	return (i);
}

long	power_aux(long nbr, size_t exp)
{
	long	ret;
	if (exp == 0)
		return (1);
	ret = nbr;
	while (exp)
	{
		ret *= nbr;
		exp--;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*str_nbr;
	long	nbr;
	size_t	len;
	size_t	i;
	long	ret_pwr;

	nbr = n;
	len = log_ten(nbr);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (str_nbr == NULL)
		return (str_nbr);
	i = 0;
	if (nbr < 0)
	{
		str_nbr[i] = '-';
		i++;
		nbr *= -1;
		len--;
	}
	printf("len: %lu\n", len);
	while (i < len)
	{
		ret_pwr = power_aux(10, len - i - 1);
		printf("power: %ld\n", ret_pwr);
		str_nbr[i] = (nbr / power_aux(10, len - 1)) + '0';
		i++;
		len--;
	}
	str_nbr[i] = '\0';
	return (str_nbr);
}

int main(void)
{
	int	n1;
	int	n2;
	char	*s1;
	char	*s2;

	n1 = -123456789;
	n2 = 123456789;
	s1 = ft_itoa(n1);
	s2 = ft_itoa(n2);

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

}
