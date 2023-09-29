# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 16:28:03 by jiryu             #+#    #+#              #
#    Updated: 2023/09/23 21:11:43 by jiryu            ###   ########.fr        #
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