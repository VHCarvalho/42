/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:10:16 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/21 14:14:52 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *s)
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
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
