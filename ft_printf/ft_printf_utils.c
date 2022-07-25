/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:10:16 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/25 10:50:20 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = (char)c;
	while (*s != find)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

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
	return (len);
}
