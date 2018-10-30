/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** the main 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "my.h"
#include "prototypes.h"

static char  *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(84);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(84);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
}

static void check_base(char const *b)
{
    int i = 0;

    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    while (b[i]) {
        if (b[i] == '+' || b[i] == '-' || b[i] == '/' || b[i] == '*' ||
        b[i] == '%')
            exit(84);
        i = i + 1;
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (84);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_strlen(av[3]);
    expr = get_expr(size);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    return (EXIT_SUCCESS);
}
