# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:50:37 by oroy              #+#    #+#              #
#    Updated: 2024/09/10 10:38:30 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= RPN

OBJDIR	:= obj
SRC		:= main.cpp RPN.cpp
OBJ		:= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 -g

RM		:= rm -rf

JUNK	:=	*.dSYM

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

run: $(NAME)
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@./$(NAME) "7 7 * 7 -"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@./$(NAME) "(1 + 1)"
	@./$(NAME) "1 -"
	@./$(NAME) "+"
	@./$(NAME) "5 6 /"
	@./$(NAME) "5 6 7 / *"
	@./$(NAME) "56+"
	@./$(NAME) "56+34-7"
	@./$(NAME) ""
	@./$(NAME) "NULL"
	@./$(NAME)

# VALGRIND ******************************************************************* #

vleaks:
	$(MAKE)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--show-possibly-lost=yes \
	--track-origins=yes \
	./$(NAME) "1 2 * 2 / 2 * 2 4 5 - +"
