# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 13:52:25 by syamashi          #+#    #+#              #
#    Updated: 2021/06/07 13:19:40 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
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
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	@echo
	@echo "------ limit test ------"
	./$(NAME) +inf
	@echo
	./$(NAME) +inff
	@echo
	./$(NAME) -inf
	@echo
	./$(NAME) -inff
	@echo
	./$(NAME) nan
	@echo
	./$(NAME) nanf
	@echo
	@echo "------ char test ------"
	./$(NAME) a
	@echo
	./$(NAME) '*'
	@echo
	./$(NAME) 100
	@echo
	./$(NAME) 127
	@echo
	./$(NAME) 128
	@echo
	./$(NAME) 31
	@echo
	./$(NAME) -1
	@echo
	@echo "------ int test ------"
	./$(NAME) 2147483647
	@echo
	./$(NAME) 2147483648
	@echo
	./$(NAME) -2147483648
	@echo
	./$(NAME) -2147483649
	@echo
	@echo "------ float test ------"
	./$(NAME) 0.0f
	@echo
	./$(NAME) -4.2f
	@echo
	./$(NAME) 4.2f
	@echo
	./$(NAME) 123456789023456789012345678901234567890.012f
	@echo
	./$(NAME) 1234567890234567890123456789012345678901.23f
	@echo
	./$(NAME) -123456789023456789012345678901234567890.012f
	@echo
	./$(NAME) -1234567890234567890123456789012345678901.23f
	@echo
	@echo "------ double test ------"
	./$(NAME) 0.0
	@echo
	./$(NAME) -4.2
	@echo
	./$(NAME) 4.2
	@echo
	./$(NAME) 123456789023456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.012
	@echo
	./$(NAME) 1234567890234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901.012
	@echo
	./$(NAME) -123456789023456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.012
	@echo
	./$(NAME) -1234567890234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901.012
	@echo
	@echo "------ invalid args test ------"
	./$(NAME) --123
	./$(NAME) ++123
	./$(NAME) -+123
	./$(NAME) -1.2.3
	./$(NAME) 123f
	./$(NAME) 123ff
	./$(NAME) 123.45ff
	./$(NAME) 123.
	./$(NAME) 123d
	./$(NAME) as
	./$(NAME) 123a456
	@make fclean -s


val:
	@make re -s
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nan
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42.0f
	@echo
	@echo "------ limit test ------"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) +inf
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) +inff
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -inf
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -inff
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nan
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nanf
	@echo
	@echo "------ char test ------"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) a
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) '*'
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 100
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 127
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 128
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 31
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -1
	@echo
	@echo "------ int test ------"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483647
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -2147483648
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -2147483649
	@echo
	@echo "------ float test ------"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.0f
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -4.2f
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4.2f
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123456789023456789012345678901234567890.012f
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 1234567890234567890123456789012345678901.23f
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -123456789023456789012345678901234567890.012f
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -1234567890234567890123456789012345678901.23f
	@echo
	@echo "------ double test ------"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.0
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -4.2
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 4.2
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123456789023456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.012
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 1234567890234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901.012
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -123456789023456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.012
	@echo
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -1234567890234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901.012
	@echo
	@echo "------ invalid args test ------"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) --123
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ++123
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -+123
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -1.2.3
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123f
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123ff
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123.45ff
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123.
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123d
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) as
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 123a456
	@make fclean -s

.PHONY: all fclean clean re test val