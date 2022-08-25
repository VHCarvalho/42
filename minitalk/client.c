/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:44 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/08/25 18:07:13 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

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

int	ft_atoi(const char *str)
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

void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 0)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		c = c >> 1;
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int				pid;
	unsigned char	*str;

	if (argc != 3)
	{
		printf("Correct usage: ./client [PID] [STRING]");
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	return (0);
}
