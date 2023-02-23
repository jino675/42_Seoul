# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 16:44:18 by jiryu             #+#    #+#              #
#    Updated: 2023/01/29 17:28:33 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c				\
		sub_putchar_fd.c		\
		sub_putstr_fd.c			\
		sub_putnbr_fd.c			\
		sub_putunbr_fd.c		\
		sub_putlhex_fd.c		\
		sub_putuhex_fd.c		\
		sub_putptr_fd.c
		
OBJS = $(SRCS:.c=.o)

HDRS = ft_printf.h


CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcusv


LIBFT = ./libft/libft.a
INC_OPT = -L./ -lftprintf


RM = rm -f


all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $< 
	$(AR) $(ARFLAGS) $(NAME) $@

$(LIBFT) :
	$(MAKE) -C ./libft all
	cp ./libft/libft.a ./libftprintf.a


clean :
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re : fclean all

PHONY : all clean fclean re main

main : $(NAME)
	$(CC) $(CFLAGS) $(INC_OPT) -g -o run_test main.c