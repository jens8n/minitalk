/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:51:49 by jebucoy           #+#    #+#             */
/*   Updated: 2022/11/10 22:33:23 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

void	get_bitvalue(char c, pid_t pid)
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
		i++;
		c = c >> 1;
		usleep(100);
	}
}

void	getstr_bit(char *str, pid_t pid)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		get_bitvalue(str[s], pid);
		s++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	pid = 0;
	if (ac == 3)
	{
		if (av[1])
		{
			pid = ft_atoi(av[1]);
		}
		if (av[2])
		{
			getstr_bit(av[2], pid);
		}
	}
	else
		ft_putstr_fd("three arguments, dumbass\n", 1);
}
