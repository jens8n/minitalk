/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:45:27 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/23 15:46:00 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:58:59 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/21 19:04:34 by jebucoy          ###   ########.fr       */
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
			printf(" : %c", c);
			c = 0;
			i = 0;
			printf("\n");
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, convert_tochar);
	signal(SIGUSR2, convert_tochar);
	while (1);
}