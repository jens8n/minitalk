/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:57:28 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/13 19:22:16 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(void)
{
	char	c;

	c = 'a';
	get_bitvalue(c);
	printf("hmm: %d\n", (1 << 8));
}
	//printf("this is a client\n");