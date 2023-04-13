# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:32:30 by jiryu             #+#    #+#              #
#    Updated: 2023/04/13 17:01:52 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm


SRCS = srcs/main.c				\
		srcs/push_swap.c		\
		srcs/stack.c			\
		srcs/utils.c			\
		srcs/take_input.c		\
		srcs/trivial_1.c		\
		srcs/trivial_2.c		\
		srcs/rewind.c			\
		srcs/instructions_1.c	\
		srcs/instructions_2.c	\
		srcs/instructions_3.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = srcs_bonus/main_bonus.c		\
		srcs_bonus/checker_bonus.c		\
		srcs_bonus/instructions_1_bonus.c	\
		srcs_bonus/instructions_2_bonus.c	\
		srcs_bonus/instructions_3_bonus.c	\
		srcs_bonus/take_input_bonus.c		\
		srcs_bonus/stack_bonus.c			\
		srcs_bonus/utils_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HDRS = hdrs/push_swap.h
HDRS_BONUS = hdrs_bonus/push_swap_bonus.h

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
	$(RM) -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) -rf $(NAME) $(NAME_BONUS)
	$(MAKE) -C ./libft fclean

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(LIBFT) $(OBJS_BONUS) $(HDRS_BONUS)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS_BONUS)

.PHONY : all clean fclean re bonus