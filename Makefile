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
	src/infin_compare.c
TEST = 	tests/test_base.c \
	tests/test_num_array.c \
	tests/test_num_array2.c \
	tests/test_infin_add.c \
	tests/test_infin_mul.c
TEST_OBJ = $(notdir $(SRC:.c=.o)) $(notdir $(TEST:.c=.o))

LIB_PATH = ./lib/my/
LIB = my
INCLUDE_PATH = ./include/

all:
	@echo "Not implemented."

lib:
	@$(MAKE) -s -C $(LIB_PATH)

tests_run: lib $(TEST_OBJ)
	@gcc -o test $(TEST_OBJ) -lcriterion --coverage -L$(LIB_PATH) -l$(LIB)
	@./test
	@rm -f test $(TEST_OBJ)
	@$(MAKE) -s -C $(LIB_PATH) fclean

$(TEST_OBJ):
	@gcc -c $(SRC) $(TEST) --coverage -I$(INCLUDE_PATH)

clean:
	@echo "Not implemented."

fclean:
	@echo "Not implemented."

re:
	@echo "Not implemented."

.PHONY: all lib clean fclean re tests_run