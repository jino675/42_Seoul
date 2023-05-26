# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 20:30:45 by jiryu             #+#    #+#              #
#    Updated: 2023/05/24 15:32:36 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

DIR_SRCS_MANDATORY = ./srcs_mandatory/
SRCS_MANDATORY = main.c					\
				load_images.c			\
				init_vars.c				\
				loop_hook.c				\
				loop_hook_2.c			\
				hook_functions.c		\
				move_player.c			\
				move_enemy.c			\
				move_enemy_2.c			\
				map_read.c				\
				map_read_2.c			\
				map_read_3.c			\
				utils.c

OBJS_MANDATORY = $(addprefix $(DIR_SRCS_MANDATORY), $(SRCS_MANDATORY:.c=.o))

HDRS_MANDATORY = ./hdrs_mandatory/so_long.h
EXE_MANDATORY = ./srcs_mandatory/so_long_mandatory

DIR_SRCS_BONUS = ./srcs_bonus/
SRCS_BONUS = main_bonus.c					\
				load_images_bonus.c			\
				init_vars_bonus.c				\
				loop_hook_bonus.c				\
				loop_hook_2_bonus.c			\
				hook_functions_bonus.c		\
				move_player_bonus.c			\
				move_enemy_bonus.c			\
				move_enemy_2_bonus.c			\
				map_read_bonus.c				\
				map_read_2_bonus.c			\
				map_read_3_bonus.c			\
				utils_bonus.c

OBJS_BONUS = $(addprefix $(DIR_SRCS_BONUS), $(SRCS_BONUS:.c=.o))

HDRS_BONUS = ./hdrs_bonus/so_long_bonus.h
EXE_BONUS = ./srcs_bonus/so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

DIR_LIBFT = ./libft/
LIBFT = ./libft/libft.a

INC_OPT = -I /usr/local/include/ -L /usr/local/lib/ -l mlx -L $(DIR_LIBFT) -l ft
FW_OPT = -framework OpenGL -framework AppKit

RM = rm -f
CP = cp

all : $(NAME)

$(NAME) : $(EXE_MANDATORY)
bonus : $(EXE_BONUS)

$(EXE_MANDATORY) : $(LIBFT) $(OBJS_MANDATORY) $(HDRS_MANDATORY)
	$(RM) $(EXE_BONUS)
	$(CC) $(CFLAGS) $(INC_OPT) $(FW_OPT) -o $@ $(OBJS_MANDATORY)
	$(CP) $(EXE_MANDATORY) $(NAME)

$(EXE_BONUS) : $(LIBFT) $(OBJS_BONUS) $(HDRS_BONUS)
	$(RM) $(EXE_MANDATORY)
	$(CC) $(CFLAGS) $(INC_OPT) $(FW_OPT) -o $@ $(OBJS_BONUS)
	$(CP) $(EXE_BONUS) $(NAME)

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT) all
	$(MAKE) -C $(DIR_LIBFT) clean
	
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS_MANDATORY)
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(EXE_MANDATORY) $(EXE_BONUS)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re bonus