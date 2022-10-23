# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:15:10 by jebucoy           #+#    #+#              #
#    Updated: 2022/10/23 15:57:01 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

S_NAME	= server

C_NAME	=	client

CC		= 		gcc

CFLAGS	= -Wall -Wextra -Werror 

S_SRC	=	server.c \

S_OBJS	=	$(S_SRC:.c=.o)


# $(S_NAME)	:	$(S_OBJS)
# 				$(CC) $(CFLAGS) $(S_OBJS) -o $(S_NAME)

C_SRC	=	client.c \
			ft_atoi.c \

C_OBJS	=	$(C_SRC:.c=.o)

RM	=	rm -rf

$(NAME)		:	$(C_OBJS) $(S_OBJS)
				$(CC) $(CFLAGS) $(C_OBJS) -o $(C_NAME)
				$(CC) $(CFLAGS) $(S_OBJS) -o $(S_NAME)
# $(C_NAME)	:	$(C_OBJS)
# 				$(CC) $(CFLAGS) $(C_OBJS) -o $(C_NAME)


all :	$(NAME)

clean	:	
		$(RM) $(S_OBJS) $(C_OBJS)

fclean	:	clean
		$(RM) $(C_NAME) $(S_NAME)

re		: fclean all
			

