/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:32:17 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/21 14:37:17 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_arg(const char *str, int i, va_list list)
{
	if (str[i + 1] == '%')
		return (ft_putchar(str[i + 1]));
	else if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(list, char *)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int 	ret;

	i = 0;
	ret = 0;
	va_start(list, str);

	while (str[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
        {
            ret += print_arg(str, i, list);
            i++;
        }
        else
            ret += ft_putchar(format[i]);
        i++;
    }
	va_end(ap);
	return (ret);
}

int main (void)
{
	ft_printf("Vamos a la %c aya", 'p');
	return (0);
}
