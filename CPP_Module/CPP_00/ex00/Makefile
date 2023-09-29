# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 16:07:04 by jiryu             #+#    #+#              #
#    Updated: 2023/09/23 21:11:14 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = src/megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

GPP = g++
CPPFLAGS = -Wall -Wextra -Werror

STD = -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(GPP) $(CPPFLAGS) $(STD) -o $@ $^

%.o : %.cpp
	$(GPP) $(CPPFLAGS) $(STD) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean