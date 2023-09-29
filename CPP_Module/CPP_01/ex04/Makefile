# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 17:55:25 by jiryu             #+#    #+#              #
#    Updated: 2023/09/26 17:28:11 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Sed

HDRS = hdr/Sed.hpp

SRCS = src/main.cpp		\
		src/Sed.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

GPP = g++
CPPFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

INC_OPT = -I hdr/

STD = -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(GPP) $(CPPFLAGS) $(STD) -o $@ $^

%.o : %.cpp
	$(GPP) $(CPPFLAGS) $(STD) $(INC_OPT) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all re fclean clean