# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 21:54:34 by jiryu             #+#    #+#              #
#    Updated: 2023/09/30 22:01:55 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed_point

HDRS = hdr/Fixed.hpp

SRCS = src/Fixed.cpp	\
		src/main.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror

STD = -std=c++98

INC = -I hdr/

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(STD) -o $@ $^

%.o : %.cpp $(HDRS)
	$(CPP) $(CPPFLAGS) $(STD) $(INC) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY : all re fclean clean