# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 20:23:42 by jiryu             #+#    #+#              #
#    Updated: 2023/06/24 17:10:23 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

DIR_SRCS_MANDATORY = ./srcs_mandatory/
SRCS_MANDATORY = main.c					\
					init.c				\
					run_philo.c			\
					utils.c

OBJS_MANDATORY = $(addprefix $(DIR_SRCS_MANDATORY), $(SRCS_MANDATORY:.c=.o))

HDRS_MANDATORY = ./hdrs_mandatory/philo.h
EXE_MANDATORY = ./srcs_mandatory/philo_mandatory

# DIR_SRCS_BONUS = ./srcs_bonus/
# SRCS_BONUS = main_bonus.c					\
# 				load_images_bonus.c			\
# 				init_vars_bonus.c				\
# 				loop_hook_bonus.c				\
# 				loop_hook_2_bonus.c			\
# 				hook_functions_bonus.c		\
# 				move_player_bonus.c			\
# 				move_enemy_bonus.c			\
# 				move_enemy_2_bonus.c			\
# 				map_read_bonus.c				\
# 				map_read_2_bonus.c			\
# 				map_read_3_bonus.c			\
# 				utils_bonus.c

# OBJS_BONUS = $(addprefix $(DIR_SRCS_BONUS), $(SRCS_BONUS:.c=.o))

# HDRS_BONUS = ./hdrs_bonus/so_long_bonus.h
# EXE_BONUS = ./srcs_bonus/so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -f
CP = cp

all : $(NAME)

$(NAME) : $(EXE_MANDATORY)
# bonus : $(EXE_BONUS)

$(EXE_MANDATORY) : $(LIBFT) $(OBJS_MANDATORY) $(HDRS_MANDATORY)
# $(RM) $(EXE_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_MANDATORY)
	$(CP) $(EXE_MANDATORY) $(NAME)

# $(EXE_BONUS) : $(LIBFT) $(OBJS_BONUS) $(HDRS_BONUS)
# 	$(RM) $(EXE_MANDATORY)
# 	$(CC) $(CFLAGS) $(INC_OPT) $(FW_OPT) -o $@ $(OBJS_BONUS)
# 	$(CP) $(EXE_BONUS) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS_MANDATORY)
# $(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(EXE_MANDATORY)

re : fclean all

.PHONY : all clean fclean re