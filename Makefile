# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:15:10 by jebucoy           #+#    #+#              #
#    Updated: 2022/11/02 16:19:37 by jebucoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	gcc

CFLAGS	= -Wall -Wextra -Werror -I ${HEADER}

RM	=	rm -rf

HEADER	=	inc

S_NAME	=	server

S_SRC	=	mandatory/server.c \

S_OBJS	=	$(S_SRC:.c=.o)


C_NAME	=	client

C_SRC	=	mandatory/client.c \

C_OBJS	=	$(C_SRC:.c=.o)


UTILS	=	utils/ft_atoi.c \
			utils/ft_putchar_fd.c \
			utils/ft_putnbr_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c \

U_OBJS	=	$(UTILS:.c=.o)

all	:	$(U_OBJS) $(S_NAME) $(C_NAME)

$(S_NAME)		:	$(S_OBJS)
				$(CC) $(CFLAGS) $(S_OBJS) $(U_OBJS) -o $(S_NAME) 

$(C_NAME)	:		$(C_OBJS)
				$(CC) $(CFLAGS) $(C_OBJS) $(U_OBJS) -o $(C_NAME)

clean	:	
		$(RM) $(S_OBJS) $(C_OBJS) $(U_OBJS)

fclean	:	clean
		$(RM) $(C_NAME) $(S_NAME)

re		: fclean all
			

