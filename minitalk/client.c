/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:44 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/09/04 12:48:41 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"

void	signal_error(void)
{
	ft_putstr_fd("client: unexpected error.\n", 1);
	exit(EXIT_FAILURE);
}

void	send_char(int pid, unsigned char str)
{
	int	bit;
	char	c;

	bit = 0;
	c = str; 
	while (bit < 8)
	{
		if (c % 2 == 0)
		{
			if(kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if(kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		c = c >> 1;
		usleep(500);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int				pid;
	unsigned char	*str;

	if (argc != 3)
	{
		ft_putstr_fd("Correct usage: ./client [PID] [STRING]",1);
	}
	pid = ft_atoi(argv[1]);
	str = (unsigned char *)argv[2];
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	return (0);
}
