# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 11:27:22 by dmusulas          #+#    #+#              #
#    Updated: 2025/01/27 13:47:09 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP             = c++
CPPFLAGS        = -Wall -Wextra -Werror -std=c++98
NAME            = account 
MAKE            = make
RM              = rm -rf

SRCS            = Account.cpp tests.cpp

OBJS            = $(SRCS:%.cpp=obj/%.o)
OBJ_DIR         = obj

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $@

obj/%.o: %.cpp | $(OBJ_DIR)
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
