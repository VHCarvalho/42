/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:48:18 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/16 09:18:44 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_blank(const char str)
{
	if (str == '\t' || str == '\n' || str == '\v' || str == '\f'
		|| str == '\r' || str == ' ')
		return (1);
	return (0);
}

int	is_overflow(int neg)
{
	if (neg > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	ret;
	long	tmp;

	neg = 1;
	i = 0;
	while (is_blank(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = ret;
		ret = (ret * 10) + (str[i] - '0');
		if (tmp > ret)
			return (is_overflow(neg));
		i++;
	}
	return (ret * neg);
}
