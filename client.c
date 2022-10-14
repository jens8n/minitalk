/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:57:28 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/14 15:47:33 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <signal.h>

void	get_bitvalue(char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
			printf("1");
		else
			printf("0");
		i++;
		c = c >> 1;
	}
}

void	getstr_bit(char *str)
{
	int s; 

	s = 0;
	while (str[s] != '\0')
	{
		get_bitvalue(s);
		s++;
		printf("\n");
	}
}
man
int	main(void)
{

	char str[] = "assuhduh";
	getstr_bit(str);
	printf("\n bit value: %d\n", (1 << 7));
}
	//printf("this is a client\n");