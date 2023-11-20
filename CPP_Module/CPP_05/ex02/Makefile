# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 14:50:10 by jiryu             #+#    #+#              #
#    Updated: 2023/10/22 17:20:43 by jiryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRCS = src/main.cpp				\
		src/Bureaucrat.cpp		\
		src/Form.cpp

OBJS = $(SRCS:.cpp=.o)

HDRS = hdr/Bureaucrat.hpp		\
		hdr/Form.hpp

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

INC = -I ./hdr/

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o : %.cpp $(HDRS)
	$(CPP) $(CPPFLAGS) $(INC) -c -o $@ $<

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all re clean fclean