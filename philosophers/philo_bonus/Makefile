# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 20:23:42 by jiryu             #+#    #+#              #
#    Updated: 2023/07/08 17:28:42 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRCS_BONUS = ./srcs_bonus/
SRCS_BONUS = main_bonus.c				\
				init_bonus.c			\
				run_philo_bonus.c		\
				in_process_bonus.c		\
				in_process_2_bonus.c	\
				utils_bonus_1.c			\
				utils_bonus_2.c			\
				utils_bonus_3.c

OBJS_BONUS = $(addprefix $(DIR_SRCS_BONUS), $(SRCS_BONUS:.c=.o))

HDRS_BONUS = ./hdrs_bonus/philo_bonus.h
EXE_BONUS = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
CP = cp

all : $(EXE_BONUS)

$(EXE_BONUS) : $(OBJS_BONUS) $(HDRS_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(EXE_BONUS)

re : fclean all

.PHONY : all clean fclean re