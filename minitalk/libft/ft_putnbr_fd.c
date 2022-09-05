/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:47:33 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/18 10:02:56 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		ft_putchar_fd(c, fd);
		return ;
	}
	else
		ft_putnbr_fd(nbr / 10, fd);
	ft_putnbr_fd(nbr % 10, fd);
}
