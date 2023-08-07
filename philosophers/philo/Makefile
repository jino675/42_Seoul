# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 20:23:42 by jiryu             #+#    #+#              #
#    Updated: 2023/07/13 19:05:11 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRCS_MANDATORY = ./srcs_mandatory/
SRCS_MANDATORY = main.c					\
					init.c				\
					run_philo.c			\
					in_thread.c			\
					in_thread_2.c		\
					utils.c

OBJS_MANDATORY = $(addprefix $(DIR_SRCS_MANDATORY), $(SRCS_MANDATORY:.c=.o))

HDRS_MANDATORY = ./hdrs_mandatory/philo.h
EXE_MANDATORY = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
CP = cp

all : $(EXE_MANDATORY)

$(EXE_MANDATORY) : $(OBJS_MANDATORY) $(HDRS_MANDATORY)
	$(CC) $(CFLAGS) -o $@ $(OBJS_MANDATORY)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS_MANDATORY)

fclean : clean
	$(RM) $(EXE_MANDATORY)

re : fclean all

.PHONY : all clean fclean re