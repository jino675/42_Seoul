# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 16:28:03 by jiryu             #+#    #+#              #
#    Updated: 2023/09/29 19:45:19 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRCS = src/Account.cpp		\
		src/tests.cpp

HDRS = hdr/Account.hpp		\

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror

INC_OPT = -I ./hdr/

STD = -std=c++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(STD) -o $@ $^

%.o : %.cpp $(HDRS)
	$(CPP) $(CPPFLAGS) $(STD) $(INC_OPT) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE)	all

.PHONY : all re fclean clean