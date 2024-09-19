# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:50:37 by oroy              #+#    #+#              #
#    Updated: 2024/09/18 21:44:59 by olivierroy       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= PmergeMe

OBJDIR	:= obj
SRC		:= main.cpp
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
	@./$(NAME) 2 1
	@./$(NAME) 3 5 9 "7 4"
	@./$(NAME) "10 11 9 4" 5 0 1
	@./$(NAME) "10 11 9 4" 5 0 1 2 123 45 788 60 31 21 13 62 34
	@./$(NAME) "10 11 9 4" 5 0 1 2 123 45 788 60 31 21 13 62 34 10 22 987 201 0

bad: $(NAME)
	@./$(NAME) 7a 2 5
	@./$(NAME) -1 2 5
	@./$(NAME) 2 5 2147483648
	@./$(NAME) 0 2.2
	@./$(NAME) 0
	@./$(NAME)

# TEST ******************************************************************* #

TEST1 = `jot -r 3000 1 100000 | tr '\n' ' '`
TEST2 = `awk 'BEGIN { srand(); while (length(arr) < 23) { num = int(rand() * 23) + 1; if (!(num in arr)) { arr[num]; print num } } }'`
TEST3 = `awk 'BEGIN { srand(); while (length(arr) < 100) { num = int(rand() * 100) + 1; if (!(num in arr)) { arr[num]; print num } } }'`
TEST4 = `awk 'BEGIN { srand(); while (length(arr) < 1000) { num = int(rand() * 1000) + 1; if (!(num in arr)) { arr[num]; print num } } }'`
TEST5 = `awk 'BEGIN { srand(); while (length(arr) < 3000) { num = int(rand() * 3000) + 1; if (!(num in arr)) { arr[num]; print num } } }'`
TEST6 = `awk 'BEGIN { srand(); while (length(arr) < 5000) { num = int(rand() * 5000) + 1; if (!(num in arr)) { arr[num]; print num } } }'`
TEST7 = `awk 'BEGIN { srand(); while (length(arr) < 10000) { num = int(rand() * 10000) + 1; if (!(num in arr)) { arr[num]; print num } } }'`
TEST8 = `awk 'BEGIN { srand(); while (length(arr) < 15000) { num = int(rand() * 15000) + 1; if (!(num in arr)) { arr[num]; print num } } }'`

test1: $(NAME)
	@./$(NAME) $(TEST1)

test2: $(NAME)
	@./$(NAME) $(TEST2)

test3: $(NAME)
	@./$(NAME) $(TEST3)

test4: $(NAME)
	@./$(NAME) $(TEST4)

test5: $(NAME)
	@./$(NAME) $(TEST5)

test6: $(NAME)
	@./$(NAME) $(TEST6)

test7: $(NAME)
	@./$(NAME) $(TEST7)

test8: $(NAME)
	@./$(NAME) $(TEST8)

# VALGRIND ******************************************************************* #

vleaks:
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--show-possibly-lost=yes \
	--track-origins=yes \
	./$(NAME) $(TEST1)
