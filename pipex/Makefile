# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 19:51:55 by jiryu             #+#    #+#              #
#    Updated: 2023/05/03 21:35:26 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DIR_SRCS_MANDATORY = ./srcs_mandatory/
SRCS_MANDATORY = main.c					\
			pipex.c						\
			pre_exec.c					\
			utils.c						\
			split_quote.c				\
			split_quote_2.c				\
			here_doc.c
		
OBJS_MANDATORY = $(addprefix $(DIR_SRCS_MANDATORY), $(SRCS_MANDATORY:.c=.o))

HDRS_MANDATORY = ./hdrs_mandatory/pipex.h
EXE_MANDATORY = ./srcs_mandatory/pipex_mandatory


DIR_SRCS_BONUS = ./srcs_bonus/
SRCS_BONUS = main_bonus.c				\
		pipex_bonus.c					\
		pre_exec_bonus.c				\
		utils_bonus.c					\
		split_quote_bonus.c				\
		split_quote_2_bonus.c			\
		here_doc_bonus.c

OBJS_BONUS = $(addprefix $(DIR_SRCS_BONUS), $(SRCS_BONUS:.c=.o))

HDRS_BONUS = ./hdrs_bonus/pipex_bonus.h
EXE_BONUS = ./srcs_bonus/pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

CP = cp
RM = rm -f

LIBFT = ./libft/libft.a
DIR_LIBFT = ./libft/
INC_OPT = -L./libft/ -lft

all : $(NAME)
$(NAME) : $(EXE_MANDATORY)
bonus : $(EXE_BONUS)

$(EXE_MANDATORY) : $(LIBFT) $(OBJS_MANDATORY) $(HDRS_MANDATORY)
	$(RM) $(EXE_BONUS)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS_MANDATORY)
	$(CP) $(EXE_MANDATORY) $(NAME)

$(EXE_BONUS) : $(LIBFT) $(OBJS_BONUS) $(HDRS_BONUS)
	$(RM) $(EXE_MANDATORY)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS_BONUS)
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

.PHONY : all fclean clean re bonus
