/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:50:42 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/19 08:53:30 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char	*str_nbr;
	long	nbr;
	size_t	len;

	nbr = n;
	len = log_ten(nbr);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (str_nbr == NULL)
		return (str_nbr);
	if (nbr < 0)
	{
		str_nbr[0] = '-';
		nbr *= -1;
	}
	str_nbr[len] = '\0';
	while (len > 0)
	{
		if (nbr / 10 < 1)
			break ;
		str_nbr[len-- - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str_nbr[len - 1] = nbr + '0';
	return (str_nbr);
}
