##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for the bistromatic project
##

SRC = 	src/base.c \
	src/num_array.c \
	src/infin_add.c \
	src/infin_mul.c \
	src/infin_compare.c	\
	src/main.c
TEST = 	tests/test_base.c \
	tests/test_num_array.c \
	tests/test_num_array2.c \
	tests/test_infin_add.c \
	tests/test_infin_mul.c \
	tests/test_infin_compare.c
TEST_OBJ = $(notdir $(SRC:.c=.o)) $(notdir $(TEST:.c=.o))

OBJ = $(notdir $(SRC:.c=.o))

NAME = calc

LIB_PATH = ./lib/my/
LIB = my
INCLUDE_PATH = ./include/

all: lib
	gcc -c $(SRC)
	gcc -Wall -Werror -Wextra --pedantic -o $(NAME) $(OBJ) -L$(LIB_PATH) -l$(LIB)

lib:
	@$(MAKE) -s -C $(LIB_PATH) clean

tests_run: lib $(TEST_OBJ)
	@gcc -o test $(TEST_OBJ) -lcriterion --coverage -L$(LIB_PATH) -l$(LIB)
	@./test
	@rm -f test $(TEST_OBJ)
	@$(MAKE) -s -C $(LIB_PATH) fclean

$(TEST_OBJ):
	@gcc -c $(SRC) $(TEST) --coverage -I$(INCLUDE_PATH)

clean:
	rm -f $(LIB_PATH)$(OBJ)	
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean re

.PHONY: all lib clean fclean re tests_run
