/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** Checks the errors
*/

#include <stdlib.h>

void check_parenthesis(char *str, char *operators)
{
    int i = 0;
    int p = 0;

    while (str[i]) {
        if (str[i] == operators[0])
            p++;
        if (str[i] == operators[0])
            p--;
        i++;
    }
    if (p != 0)
        exit(84);
}
