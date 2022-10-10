# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAkefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:15:10 by jebucoy           #+#    #+#              #
#    Updated: 2022/10/10 15:57:21 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME	= server

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror 

S_SRC	=	server.c \

S_OBJS	=	$(S_SRC:*.c=*.o)

$(S_NAME)	:	$(S_OBJS)
			$(CC) $(CFLAGS) $(S_OBJS) -o $(S_NAME)

C_NAME	=	client

C_SRC	=	client.c

C_OBJS	=	$(C_SRC:*.c=*.o)

RM	=	rm -rf

$(C_NAME)	:	$(C_OBJS)

all :	$(S_NAME) $(C_NAME)

clean	:	
		$(RM) $(S_NAME) $(C_NAME)
			

