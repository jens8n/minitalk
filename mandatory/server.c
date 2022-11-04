/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:58:59 by jebucoy           #+#    #+#             */
/*   Updated: 2022/11/02 19:26:07 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_tochar(int sig)
{
	static char		c = 0;
	static int		i = 0;

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
	}
}

int	main(void)
{
	pid_t	pid;
	char	*msg;
	char	*msg2;

	msg = "\n\t ⏳To continue, please wait for your PID to be generated\t\n";
	msg2 = "\n\tRun the client with the PID provided and a message to send \n";
	ft_putstr_fd("\n\t\t\t\t MINITALK 🗯 \t\n", 1);
	ft_putstr_fd(msg, 1);
	pid = getpid();
	sleep(1);
	ft_putstr_fd("\n\t\t\t\tPID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(msg2, 1);
	signal(SIGUSR1, convert_tochar);
	signal(SIGUSR2, convert_tochar);
	while (1)
	{
		pause();
	}
}

