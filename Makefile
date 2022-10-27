# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:15:10 by jebucoy           #+#    #+#              #
#    Updated: 2022/10/27 20:50:14 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

S_NAME	=	server

CC		= 	gcc

CFLAGS	= -Wall -Wextra -Werror -I ${HEADER}

HEADER	=	inc

S_SRC	=	mandatory/server.c \

S_OBJS	=	$(S_SRC:.c=.o)

$(S_NAME)		:	$(S_OBJS)
				$(CC) $(CFLAGS) $(S_OBJS) $(U_OBJS) -o $(S_NAME) 

C_NAME	=	client

C_SRC	=	mandatory/client.c \

C_OBJS	=	$(C_SRC:.c=.o)

$(C_NAME)	:		$(C_OBJS)
				$(CC) $(CFLAGS) $(C_OBJS) $(U_OBJS) -o $(C_NAME) 

UTILS	=	utils/ft_atoi.c \
			utils/ft_putchar_fd.c \
			utils/ft_putnbr_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c \

U_OBJS	=	$(UTILS:.c=.o)

RM	=	rm -rf

all :	$(NAME)

clean	:	
		$(RM) $(S_OBJS) $(C_OBJS) $(U_OBJS)

fclean	:	clean
		$(RM) $(C_NAME) $(S_NAME)

re		: fclean all
			

