# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 19:51:55 by jiryu             #+#    #+#              #
#    Updated: 2023/05/03 21:10:19 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./pipex

DIR_SRCS = ./src/
SRCS = main.c						\
		pipex.c						\
		pre_exec.c					\
		utils.c						\
		split_quote.c				\
		split_quote_2.c				\
		here_doc.c
		
OBJS = $(addprefix $(DIR_SRCS), $(SRCS:.c=.o))
EXE = ./src/pipex_mandatory

HDRS = ./hdr/pipex.h

DIR_SRCS_BONUS = ./src_bonus/
SRCS_BONUS = main_bonus.c				\
		pipex_bonus.c					\
		pre_exec_bonus.c				\
		utils_bonus.c					\
		split_quote_bonus.c				\
		split_quote_2_bonus.c			\
		here_doc_bonus.c

OBJS_BONUS = $(addprefix $(DIR_SRCS_BONUS), $(SRCS_BONUS:.c=.o))

HDRS_BONUS = ./hdr_bonus/pipex_bonus.h
EXE_BONUS = ./src_bonus/pipex_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

CP = cp
RM = rm -f

LIBFT = ./libft/libft.a
DIR_LIBFT = ./libft/
INC_OPT = -L./libft/ -lft

all : $(NAME)
$(NAME) : $(EXE)
bonus : $(EXE_BONUS)

$(EXE) : $(LIBFT) $(OBJS) $(HDRS)
	$(RM) $(EXE_BONUS)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS)
	$(CP) $(EXE_BONUS) $(NAME)

$(EXE_BONUS) : $(LIBFT) $(OBJS_BONUS) $(HDRS_BONUS)
	$(RM) $(EXE)
	$(CC) $(CFLAGS) $(INC_OPT) -o $@ $(OBJS_BONUS)
	$(CP) $(EXE) $(NAME)

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT) all
	$(MAKE) -C $(DIR_LIBFT) clean

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) -f $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

.PHONY : all fclean clean re bonus
