/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:32:17 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/25 11:12:06 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(const char *str, int i, va_list list)
{
	if (str[i + 1] == '%')
		return (ft_putchar(str[i + 1]));
	else if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (str[i + 1] == 'p')
		return (ft_putptr(va_arg(list, unsigned long), "0123456789abcdef"));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (str[i + 1] == 'u')
		return (ft_putuns(va_arg(list, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_puthex(va_arg(list, unsigned int), "0123456789abcdef"));
	else if (str[i + 1] == 'X')
		return (ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF"));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			ret += print_arg(str, i, list);
			i++;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (ret);
}
