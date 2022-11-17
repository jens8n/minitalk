/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:53:27 by jebucoy           #+#    #+#             */
/*   Updated: 2022/11/15 19:29:00 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	convert_tochar(int sig, siginfo_t *info, void *context)
{
	static char		c = 0;
	static int		i = 0;

	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR2)
		{
			c = c | (1 << i);
		}
		i++;
		if (i == 8)
		{
			ft_putchar_fd(c, 1);
			c = 0;
			i = 0;
		}
		usleep(100);
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &convert_tochar;
	ft_putstr_fd("\n\t\t\t\t MINITALK 🗯\n", 1);
	ft_putstr_fd("\n\t ⏳To continue, "
		"please wait for your PID to be generated⏳\n", 1);
	pid = getpid();
	sleep(1);
	ft_putstr_fd(GREEN"\n\t\t\t\tPID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n"RESET, 1);
	ft_putstr_fd("\n\tRun the client with the "
		"PID provided and a message to send\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
