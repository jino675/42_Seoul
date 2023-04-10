# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 18:12:11 by jiryu             #+#    #+#              #
#    Updated: 2023/01/22 18:14:02 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HDRS = libft.h

OBJS =	ft_isalpha.o		\
		ft_isdigit.o		\
		ft_isalnum.o		\
		ft_isascii.o		\
		ft_isprint.o		\
		ft_strlen.o			\
		ft_memset.o			\
		ft_toupper.o		\
		ft_tolower.o		\
		ft_bzero.o			\
		ft_memcpy.o			\
		ft_memmove.o		\
		ft_memchr.o			\
		ft_memcmp.o			\
		ft_strchr.o			\
		ft_strrchr.o		\
		ft_strncmp.o		\
		ft_strlcpy.o		\
		ft_strlcat.o		\
		ft_strnstr.o		\
		ft_atoi.o			\
		ft_calloc.o			\
		ft_strdup.o			\
		ft_substr.o			\
		ft_strjoin.o		\
		ft_strtrim.o		\
		ft_split.o			\
		ft_itoa.o			\
		ft_strmapi.o		\
		ft_striteri.o		\
		ft_putchar_fd.o		\
		ft_putstr_fd.o		\
		ft_putendl_fd.o		\
		ft_putnbr_fd.o
		
OBJS_BONUS =	ft_lstnew.o			\
				ft_lstadd_front.o	\
				ft_lstsize.o		\
				ft_lstlast.o		\
				ft_lstadd_back.o	\
				ft_lstdelone.o		\
				ft_lstclear.o		\
				ft_lstiter.o		\
				ft_lstmap.o
				
all : $(NAME) $(HDRS)

$(NAME) : $(OBJS) $(HDRS)

bonus : $(OBJS_BONUS)

%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<
	ar -rcusv $(NAME) $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re