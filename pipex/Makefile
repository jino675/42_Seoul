# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 20:28:00 by jiryu             #+#    #+#              #
#    Updated: 2023/04/28 16:22:50 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = main.c						\
		pipex.c						\
		pre_exec.c					\
		utils.c						\
		split_quote_brace.c			\
		split_quote_brace_2.c		\
		split_awk.c

OBJS = $(SRCS:.c=.o)

HDRS = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm

LIBFT = ./libft/libft.a
INC_OPT = -L./libft/ -lft

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS)

$(LIBFT) :
	$(MAKE) -C ./libft/ all
	$(MAKE) -C ./libft/ clean

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) -f $(OBJS)

fclean : clean
	$(RM) -f $(NAME)
	$(MAKE) -C ./libft/ fclean

re : fclean all

.PHONY : all fclean clean re