# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 07:44:04 by dmusulas          #+#    #+#              #
#    Updated: 2025/01/27 07:47:19 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME			= phonebook
MAKE			= make
RM				= rm -rf

SRCS			= main.cpp PhoneBook.cpp Contact.cpp

OBJS			= $(SRCS:%.cpp=obj/%.o)
OBJ_DIRS		= $(sort $(dir $(OBJS)))

all: $(NAME)

$(OBJ_DIRS):
		@mkdir -p $@

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $@

obj/%.o: %.cpp | $(OBJ_DIRS)
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		$(RM) obj

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
