# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 16:28:03 by jiryu             #+#    #+#              #
#    Updated: 2023/09/29 19:38:56 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = src/PhoneBook.cpp		\
		src/Contact.cpp			\
		src/main.cpp

HDRS = hdr/PhoneBook.hpp		\
		hdr/Contact.hpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror

INC = -I ./hdr

STD = -std=c++98

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
	$(MAKE)	all

.PHONY : all re fclean clean