# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:32:30 by jiryu             #+#    #+#              #
#    Updated: 2023/04/10 15:35:39 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm


SRCS = push_swap.c			\
		main.c				\
		stack.c				\
		utils.c				\
		receive.c			\
		trivial.c			\
		rewind.c			\
		instructions_1.c	\
		instructions_2.c	\
		instructions_3.c	\

OBJS = $(SRCS:.c=.o)

HDRS = push_swap.h

LIBFT = libft/libft.a
INC_OPT = -L./libft/ -lft


all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS)

$(LIBFT) : 
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft clean

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) -rf $(OBJS)

fclean : clean
	$(RM) -rf $(NAME)
	$(MAKE) -C ./libft fclean

re : fclean all

PHONY : all clean fclean re