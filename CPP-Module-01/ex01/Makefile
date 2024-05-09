# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:50:37 by oroy              #+#    #+#              #
#    Updated: 2024/01/19 15:55:56 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= zombiehorde

OBJDIR	:= obj
SRC		:= main.cpp Zombie.cpp zombieHorde.cpp
OBJ		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98

RM		:= rm -rf

# RULES ********************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) -c $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# VALGRIND ******************************************************************* #

vleaks:
	$(MAKE)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--show-possibly-lost=yes \
	--track-origins=yes \
	./$(NAME)