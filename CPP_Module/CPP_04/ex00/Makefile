# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 10:32:41 by jiryu             #+#    #+#              #
#    Updated: 2023/10/05 12:16:24 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

HDRS = hdr/Animal.hpp		\
		hdr/Dog.hpp			\
		hdr/Cat.hpp			\
		hdr/WrongAnimal.hpp	\
		hdr/WrongCat.hpp

SRCS = src/main.cpp			\
		src/Animal.cpp		\
		src/Dog.cpp			\
		src/Cat.cpp			\
		src/WrongAnimal.cpp	\
		src/WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98
INC = -I hdr/

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

%.o : %.cpp $(HDRS)
	$(CPP) $(CFLAGS) $(STD) $(INC) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all re fclean clean