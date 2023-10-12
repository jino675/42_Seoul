# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 17:55:25 by jiryu             #+#    #+#              #
#    Updated: 2023/09/30 16:23:53 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

HDRS = hdr/Harl.hpp

SRCS = src/main.cpp		\
		src/Harl.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror

INC_OPT = -I hdr/

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
	$(MAKE) all

.PHONY : all re fclean clean