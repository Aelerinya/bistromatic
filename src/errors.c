/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** Checks the errors
*/

#include <stdlib.h>
#include "prototypes.h"

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
