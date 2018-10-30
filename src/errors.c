/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** Checks the errors
*/

#include <stdlib.h>
#include <unistd.h>
#include "prototypes.h"

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
    if (p != 0)
        exit(84);
}
