/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:58:59 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/23 17:58:56 by jebucoy          ###   ########.fr       */
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
			printf("1");
		}
		if (sig == SIGUSR1)
		{
			printf("0");
		}
		i++;
		if (i == 8)
		{
			ft_putchar_fd(c, 1);
			c = 0;
			i = 0;
			// printf("\n");
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("\n\t MINITALK \t\n", 1);
	ft_putstr_fd("\n\t To continue, please wait for your PID to be generated\t\n", 1);
	sleep(2);
	ft_putstr_fd("\t \t PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	// sleep(2);
	ft_putstr_fd("\n\t You can now run the client with the PID provided and a message to send \t\n", 1);
	signal(SIGUSR1, convert_tochar);
	signal(SIGUSR2, convert_tochar);
	while (1);
}