# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:50:37 by oroy              #+#    #+#              #
#    Updated: 2024/05/15 12:05:43 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= form

OBJDIR	:= obj
SRC		:= main.cpp Bureaucrat.cpp Form.cpp
OBJ		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -g

RM		:= rm -rf

JUNK	:= *.dSYM

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
	$(RM) $(JUNK)

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