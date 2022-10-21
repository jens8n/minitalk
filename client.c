/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:57:28 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/21 18:22:15 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	s;
	size_t	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		n = n * 10 + (str[i++] - 48);
	return (n * s);
}

void	get_bitvalue(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
		{
			// printf("1");
			kill(pid, SIGUSR2);
		}
		else
		{
			// printf("0");
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
		printf("three arguments, dumbass\n");
}