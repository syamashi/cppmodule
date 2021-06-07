# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 13:52:25 by syamashi          #+#    #+#              #
#    Updated: 2021/06/07 09:44:46 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRCS = $(shell echo *.cpp)
OBJDIR = ./obj/
OBJS = $(SRCS:%.cpp=$(OBJDIR)%.o)

CC = clang++
CFLAGS = -Wall -Werror -Wextra

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p obj

$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	@make re -s
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)
	@make fclean -s

val:
	@make re -s
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
	@make fclean -s

.PHONY: all fclean clean re test val
