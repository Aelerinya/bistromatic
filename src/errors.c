/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** Checks the errors
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototypes.h"
#include "my.h"

void disp_usage(void)
{
    write(2, "USAGE\n./calc base operators size_read\n\nDESCRIPTION\n", 51);
    write(2, "- base: all the symbols of the base\n- operators: the ", 53);
    write(2, "symbols for the parentheses and the 5 operators\n", 48);
    write(2, "- size_read: number of characters to be read\n", 45);
    exit(84);
}

void check_parenthesis(char *str, char *operators)
{
    int p = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == operators[OP_OPENP])
            p++;
        if (str[i] == operators[OP_CLOSEP])
            p--;
    }
    if (p != 0) {
        write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
        exit(84);
    }
}

void check_ops(char *ops)
{
    int i = 0;
    int j = 1;

    while (ops[i]) {
        while (ops[j]) {
            if (ops[i] == ops[j]) {
                write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
                exit(84);
            }
            j = j + 1;
        }
        i = i + 1;
        j = i + 1;
    }
    if (my_strlen(ops) != 7) {
        write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
        exit(84);
    }
}

void check_base(char *b, char *ops)
{
    int i = 0;
    int j = 0;

    if (my_strlen(b) < 2) {
        write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
        exit(84);
    }
    while (b[i]) {
        while (ops[j]) {
            if (b[i] == ops[j]) {
                write(2, SYNTAX_ERROR_MSG, my_strlen(SYNTAX_ERROR_MSG));
                exit(84);
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
}
