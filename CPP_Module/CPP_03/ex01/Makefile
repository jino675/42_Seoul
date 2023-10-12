# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 16:34:04 by jiryu             #+#    #+#              #
#    Updated: 2023/10/03 18:55:27 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap

HDRS = hdr/ClapTrap.hpp		\
		hdr/ScavTrap.hpp

SRCS = src/main.cpp			\
		src/ClapTrap.cpp	\
		src/ScavTrap.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror
STD = -std=c++98
INC = -I ./hdr/

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(STD) -o $@ $^

%.o : %.cpp $(HDRS)
	$(CPP) $(CPPFLAGS) $(STD) $(INC) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE)	fclean
	$(MAKE) all

.PHONY : all re fclean clean