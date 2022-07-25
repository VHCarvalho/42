/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:52:16 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/25 12:54:39 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	log_hex(unsigned long nbr)
{
	size_t	i;

	i = 0;
	while (nbr > 0xF)
	{
		nbr = nbr / 0x10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_hextoa(unsigned int n, char *str)
{
	char			*str_nbr;
	unsigned int	nbr;
	size_t			len;

	nbr = n;
	len = log_hex(nbr);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (str_nbr == NULL)
		return (0);
	str_nbr[len] = '\0';
	while (len > 0)
	{
		if (nbr / 0x10 < 1)
			break ;
		str_nbr[len-- - 1] = str[(nbr % 0x10)];
		nbr = nbr / 0x10;
	}
	str_nbr[len - 1] = str[nbr];
	return (str_nbr);
}

int	ft_puthex(unsigned int nbr, char *str)
{
	size_t	len;
	char	*str_nbr;

	str_nbr = ft_hextoa(nbr, str);
	len = ft_strlen(str_nbr);
	write(1, str_nbr, len);
	free(str_nbr);
	return (len);
}

char	*ft_ptrtoa(unsigned long n, char *str)
{
	char			*str_nbr;
	unsigned long	nbr;
	size_t			len;

	nbr = n;
	len = log_hex(nbr);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (str_nbr == NULL)
		return (0);
	str_nbr[len] = '\0';
	while (len > 0)
	{
		if (nbr / 0x10 < 1)
			break ;
		str_nbr[len-- - 1] = str[(nbr % 0x10)];
		nbr = nbr / 0x10;
	}
	str_nbr[len - 1] = str[nbr];
	return (str_nbr);
}

int	ft_putptr(unsigned long n, char *str)
{
	size_t	len;
	char	*str_nbr;

	str_nbr = ft_ptrtoa(n, str);
	len = ft_strlen(str_nbr);
	write(1, "0x", 2);
	write(1, str_nbr, len);
	free(str_nbr);
	return (len + 2);
}
