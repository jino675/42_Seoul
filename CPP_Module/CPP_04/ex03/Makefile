# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 10:32:41 by jiryu             #+#    #+#              #
#    Updated: 2023/10/05 22:05:25 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = magician

HDRS = hdr/AMateria.hpp			\
		hdr/Character.hpp		\
		hdr/Cure.hpp			\
		hdr/Ice.hpp				\
		hdr/ICharacter.hpp		\
		hdr/IMateriaSource.hpp	\
		hdr/MateriaSource.hpp	\
		hdr/Scavenger.hpp

SRCS = src/AMateria.cpp			\
		src/Character.cpp		\
		src/Cure.cpp			\
		src/Ice.cpp				\
		src/MateriaSource.cpp	\
		src/main.cpp			\
		src/Scavenger.cpp

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