/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:51:49 by jebucoy           #+#    #+#             */
/*   Updated: 2022/11/17 18:21:34 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		g_var;

void	sig_ack(int sig)
{
	(void)sig;
	if (g_var == 1)
	{
		ft_putstr_fd(GREEN"MESSAGE SENT ✅\n"RESET, 1);
		exit(0);
	}
}

void	get_bitvalue(char c, pid_t pid, int flag)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		if (flag == 1 && i == 7)
		{
			g_var = 1;
		}
		i++;
		c = c >> 1;
		pause();
		usleep(50);
	}
}

void	getstr_bit(char *str, pid_t pid)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		if (str[s + 1] == '\0')
		{
			get_bitvalue(str[s], pid, 1);
		}
		else
			get_bitvalue(str[s], pid, 0);
		s++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	g_var = 0;
	pid = 0;
	signal(SIGUSR1, sig_ack);
	if (ac == 3)
	{
		if (av[1])
		{
			pid = ft_atoi(av[1]);
			if (kill(pid, 0) == -1 || pid == 0)
			{
				ft_putstr_fd(RED"INVALID PID ❌\n"RESET, 1);
				exit(0);
			}
		}
		if (av[2])
		{
			getstr_bit(av[2], pid);
		}
	}
	else
		ft_putstr_fd(RED"three arguments:\n"
			"(./client_bonus | PID | MESSAGE)\n"RESET, 1);
}
