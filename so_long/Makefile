# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 20:30:45 by jiryu             #+#    #+#              #
#    Updated: 2023/05/08 17:44:22 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

DIR_SRCS_MANDATORY = ./srcs_mandatory/
SRCS_MANDATORY = main.c					\

OBJS_MANDATORY = $(addprefix $(DIR_SRCS_MANDATORY), $(SRCS_MANDATORY:.c=.o))

HDRS_MANDATORY = ./hdrs_mandatory/so_long.h
EXE_MANDATORY = ./srcs_mandatory/so_long_mandatory

EXE_BONUS = ./srcs_bonus/so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# DIR_MLX = ./minilibx_mms_20200219/
# MLX = ./minilibx_mms_20200219/libmlx.dylib

DIR_LIBFT = ./libft/
LIBFT = ./libft/libft.a

# INC_OPT = -I $(DIR_MLX) -L $(DIR_MLX) -lmlx -L $(DIR_LIBFT) -lft
INC_OPT = -I /usr/local/include/ -L /usr/local/lib/ -l mlx -L $(DIR_LIBFT) -l ft
FW_OPT = -framework OpenGL -framework AppKit

RM = rm -f
CP = cp

all : $(NAME)

$(NAME) : $(EXE_MANDATORY)

$(EXE_MANDATORY) : $(LIBFT) $(OBJS_MANDATORY) $(HDRS_MANDATORY)
	$(RM) $(EXE_BONUS)
	$(CC) $(CFLAGS) $(INC_OPT) $(FW_OPT) -o $@ $(OBJS_MANDATORY)
	$(CP) $(EXE_MANDATORY) $(NAME)

# $(NAME) : $(LIBFT) $(MLX) $(OBJS_MANDATORY) $(HDRS_MANDATORY)
# 	$(CC) $(CFLAGS) $(INC_OPT) $(FW_OPT) -o $@ $(OBJS_MANDATORY)
# 	install_name_tool -change libmlx.dylib ./minilibx_mms_20200219/libmlx.dylib $(NAME)

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT) all
	$(MAKE) -C $(DIR_LIBFT) clean
	
# $(MLX) :
# 	$(MAKE) -C $(DIR_MLX) all
# 	$(MAKE) -C $(DIR_MLX) clean

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS_MANDATORY)

fclean : clean
	$(RM) $(NAME) $(EXE_MANDATORY) $(EXE_BONUS)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re bonus