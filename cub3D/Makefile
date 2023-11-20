# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 20:30:45 by jiryu             #+#    #+#              #
#    Updated: 2023/10/23 16:18:03 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

DIR_SRCS_MANDATORY = ./src_mandatory/
SRCS_MANDATORY = main.c					\
				utils.c					\
				init_vars.c				\
				map_read_1.c			\
				map_read_2.c			\
				map_read_3.c			\
				map_read_4.c			\
				load_images_1.c			\
				load_images_2.c			\
				hook_functions.c		\
				loop_hook.c				\
				draw_view_1.c			\
				draw_view_2.c			\
				draw_view_3.c			\
				move_player_1.c			\
				move_player_2.c			\
				use_staff_1.c			\
				use_staff_2.c			\
				draw_minimap.c			\
				change_direction.c

OBJS_MANDATORY = $(addprefix $(DIR_SRCS_MANDATORY), $(SRCS_MANDATORY:.c=.o))

DIR_HDRS_MANDATORY = ./hdr_mandatory/
HDRS_MANDATORY = ./hdr_mandatory/cub3D.h
EXE_MANDATORY = ./src_mandatory/cub3D_mandatory

DIR_SRCS_BONUS = ./src_bonus/
SRCS_BONUS = main_bonus.c					\
				utils_bonus.c					\
				init_vars_bonus.c				\
				map_read_1_bonus.c			\
				map_read_2_bonus.c			\
				map_read_3_bonus.c			\
				map_read_4_bonus.c			\
				load_images_1_bonus.c			\
				load_images_2_bonus.c			\
				hook_functions_bonus.c		\
				loop_hook_bonus.c				\
				draw_view_1_bonus.c			\
				draw_view_2_bonus.c			\
				draw_view_3_bonus.c			\
				move_player_1_bonus.c			\
				move_player_2_bonus.c			\
				use_staff_1_bonus.c			\
				use_staff_2_bonus.c			\
				draw_minimap_bonus.c			\
				change_direction_bonus.c

OBJS_BONUS = $(addprefix $(DIR_SRCS_BONUS), $(SRCS_BONUS:.c=.o))

DIR_HDRS_BONUS = ./hdr_bonus/
HDRS_BONUS = ./hdr_bonus/cub3D_bonus.h
EXE_BONUS = ./src_bonus/cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

DIR_LIBFT = ./libft/
LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a
DIR_MLX = ./mlx/

INC_HDRS = -I ./mlx/ -I ./libft/ -I ./hdr_mandatory/

INC_LIBS = -L ./mlx/ -l mlx -L ./libft/ -l ft 
FW_OPT = -framework OpenGL -framework Appkit

RM = rm -f
CP = cp

all : $(NAME)

$(NAME) : $(EXE_MANDATORY)
bonus : $(EXE_BONUS)

$(EXE_MANDATORY) : $(MLX) $(LIBFT) $(OBJS_MANDATORY) $(HDRS_MANDATORY)
	$(RM) $(EXE_BONUS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INC_LIBS) $(FW_OPT) -o $@ $(OBJS_MANDATORY)
	$(CP) $(EXE_MANDATORY) $(NAME)

$(EXE_BONUS) : $(MLX) $(LIBFT) $(OBJS_BONUS) $(HDRS_BONUS)
	$(RM) $(EXE_MANDATORY) $(OBJS_MANDATORY)
	$(CC) $(CFLAGS) $(INC_LIBS) $(FW_OPT) -o $@ $(OBJS_BONUS)
	$(CP) $(EXE_BONUS) $(NAME)

$(MLX) :
	$(MAKE) -C $(DIR_MLX) all

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT) all
	$(MAKE) -C $(DIR_LIBFT) clean
	
%.o : %.c
	$(CC) $(CFLAGS) $(INC_HDRS) -c -o $@ $<

clean :
	$(RM) $(OBJS_MANDATORY)
	$(RM) $(OBJS_BONUS)

fclean :
	$(RM) $(NAME) $(EXE_MANDATORY) $(EXE_BONUS)
	$(MAKE) -C $(DIR_LIBFT) fclean
	$(MAKE) -C $(DIR_MLX) clean
	$(MAKE) clean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus