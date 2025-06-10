# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 07:44:04 by dmusulas          #+#    #+#              #
#    Updated: 2025/06/10 18:47:27 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME			= phonebook
MAKE			= make
RM				= rm -rf
SRCDIR			= src
INCDIR			= include
SRCS			= $(SRCDIR)/main.cpp $(SRCDIR)/PhoneBook.cpp $(SRCDIR)/Contact.cpp
OBJS			= $(SRCS:$(SRCDIR)/%.cpp=obj/%.o)
OBJ_DIR			= obj

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -I$(INCDIR) $(OBJS) -o $@

obj/%.o: $(SRCDIR)/%.cpp | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
