# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 22:44:08 by dmusulas          #+#    #+#              #
#    Updated: 2025/01/27 05:07:52 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Object files are overkill for this exercise but I wrote it this way so 
# I can copy this makefile in the future

CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME			= megaphone
MAKE			= make
RM				= rm -rf

SRCS			= megaphone.cpp

OBJS			= $(SRCS:%.cpp=obj/%.o)
OBJ_DIRS		= $(sort $(dir $(OBJS)))

all: $(NAME)

$(OBJ_DIRS):
		@mkdir -p $@

$(NAME): $(OBJ_DIRS) $(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $@

obj/%.o: %.cpp | $(OBJ_DIRS)
		@mkdir -p obj
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		$(RM) obj

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
