/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:10:16 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/21 15:54:43 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	if (!s)
		writr(1, "(null)", 6);
		return ;
	while (*s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		s++;
	}
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
