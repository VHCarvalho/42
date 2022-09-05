/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:41 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/09/04 12:30:07 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	action(int sig, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	(void)info;
	if (i < 8)
	{
		if (sig == SIGUSR1)
		{
			c += 1 << i;
		}
		else
		{
			c += 0 << i;
		}
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	printf("%d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
}
