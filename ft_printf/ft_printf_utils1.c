/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:46:33 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/25 12:49:09 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putnbr(int nbr)
{
	size_t	len;
	char	*str_nbr;

	str_nbr = ft_itoa(nbr);
	len = ft_strlen(str_nbr);
	write(1, str_nbr, len);
	free(str_nbr);
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*str_nbr;
	unsigned int	nbr;
	size_t			len;

	nbr = n;
	len = log_ten(nbr);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (str_nbr == NULL)
		return (str_nbr);
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

int	ft_putuns(unsigned int nbr)
{
	size_t	len;
	char	*str_nbr;

	str_nbr = ft_utoa(nbr);
	len = ft_strlen(str_nbr);
	write(1, str_nbr, len);
	free(str_nbr);
	return (len);
}
