/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:44 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/09/04 21:37:52 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void error(unsigned char *str)
{
	if (str)
		free(str);
	exit(EXIT_FAILURE);
}
int send_null(int pid, unsigned char *str)
{
	static int bit;

	if (bit < 8)
	{
		kill(pid, SIGUSR2);
		bit++;
		return (2);
	}
	if (bit == 8)
		free(str);
	return (1);
}

int send_bit(int pid, unsigned char *str)
{
	static unsigned char	*message;
	static int						s_pid;
	static int						bit;
	static int						c;

	if (str)
		message = (unsigned char *)ft_strdup((const char *)str);
	if (!message)
		error(message);
	if (pid)
		s_pid = pid;
	if (bit % 8 == 0)
		c = message[bit / 8];
	if (message[bit / 8] == '\0')
		return (send_null(s_pid, message));
	if (c % 2 == 0)
		kill(s_pid, SIGUSR2);
	else
		kill(s_pid, SIGUSR1);
	bit++;
	c >>= 1;
	return (0);
}

void handler(int signum)
{
	int ret;

	ret = 0;
	if (signum == SIGUSR1)
		ret = send_bit(0,0);
	if (ret == 1)
	{
		ft_putstr_fd("Fim!\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char *argv[])
{
	unsigned char	*str;
	int						pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <SERVER PID> <STRING TO SEND>\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = (unsigned char *)argv[2];
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_bit(pid, str);
	while (1)
		pause();
}
