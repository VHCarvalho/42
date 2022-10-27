/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:06:15 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/26 19:08:29 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blank(const char str)
{
	if (str == '\t' || str == '\n' || str == '\v' || str == '\f'
		|| str == '\r' || str == ' ')
		return (1);
	return (0);
}

static int	is_overflow(int neg)
{
	if (neg > 0)
		return (-1);
	return (0);
}

static int	is_negative(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) < '0' || *(str + 1) > '9')
			return (0);
		if (*str == '-')
			return (-1);
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		neg;
	long	ret;
	long	tmp;

	neg = 1;
	while (is_blank(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		neg = is_negative(str);
		str++;
	}
	if (neg == 0)
		return (neg);
	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = ret;
		ret = (ret * 10) + (*str - '0');
		if (tmp > ret)
			return (is_overflow(neg));
		str++;
	}
	return (ret * neg);
}
