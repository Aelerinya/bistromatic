/*
** EPITECH PROJECT, 2018
** Main
** File description:
** Main for the bistromatic project
*/

#include "prototypes.h"
#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>
#include <unistd.h>

char *get_expression(int size)
{
    char *expression;
    
    if (size <= 0) {
        write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
        exit(84);
    }
    if (!(expression = malloc(sizeof(char) * (size + 1)))) {
        write(2, ERROR_MSG, my_strlen(ERROR_MSG));
        exit(84);
    }
    if (read(0, expression, size) != size) {
        write(2, ERROR_MSG, my_strlen(ERROR_MSG));
        exit(84);
    }
    expression[size] = '\0';
    return expression;
}

void check_digits(char *b, char *op, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i]) {
        while (b[j]) {
            if (b[j] != str[i]) {
                write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
                exit(84);
            }
            j = j + 1;
        }
        while (op[k]) {
            if (op[k] != str[i]) {
                write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
                exit(84);
            }
            k = k + 1;
        }
        j = 0;
        k = 0;
        i = i + 1;
    }
}

int main(int ac, char **av)
{
    int size;
    char *expression;
    
    if (ac != 4 || my_strcmp(av[1], "-h") == 0)
        disp_usage();
    size = my_getnbr(av[3]);
    expression = get_expression(size);
    print_number_array(eval_expr(expression, av[1], av[2]), av[1], av[2]);
    return (0);
}
