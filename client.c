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

int	get_bitvalue(char c)
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
	return (i);
}

void	getstr_bit(char *str)
{
	int s;
	int n; 

	s = 0;
	n = 0;
	while (str[s] != '\0')
	{
		n = get_bitvalue(s);
		i++;
	}
}

int	main(void)
{
	char	*str;

	str[] = "assuhduh";
	getstr_bit(str);
	printf("hmm: %d\n", (1 << 8));
}
	//printf("this is a client\n");