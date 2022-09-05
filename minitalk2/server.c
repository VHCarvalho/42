/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:41 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/09/05 17:20:18 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*addchar(char *str, char c)
{
	char		*ret;
	size_t	len;

	if (!str)
	{
		write(1, "entra", 5);
		ret = (char *)malloc(sizeof(char) * 2);
		if (!ret)
			return (NULL);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	len = ft_strlen(str);
	ret = malloc(sizeof(char) * (len + 2));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, len + 1);
	write(1, "2", 1);
	free(str);
	ret[len] = c;
	ret[len + 1] = '\0';
	return (ret);
}

void handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static int						bit;
	//static unsigned char	*str;
	static char						c;
	int										pid;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c += 1 << bit;
	else if (signum == SIGUSR2)
		c += 0 << bit;
	bit++;
	if (bit == 8)
	{
		if (c)
			ft_putchar_fd(c, 1);
			//str = (unsigned char *)addchar((char *)str, c);
		else
		{
			//str = (unsigned char *)addchar((char *)str, '\0');
			//ft_putstr_fd((char *)str, 1);
			//write(1, "1", 1);
			//free(str);
			//if (str)
			//	write(1, "ainda", 5);
			//exit(EXIT_SUCCESS);
		}
		bit = 0;
		c = 0;
	}
	if(kill(pid, SIGUSR1) == -1)
		write(1, "opa", 3);
}

int main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	
}
