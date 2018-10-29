/*
** EPITECH PROJECT, 2018
** Infin_sub
** File description:
** Substract two number arrays
*/

#include "prototypes.h"
#include <stdlib.h>

char *infin_sub(char *nb1, char *nb2, char *base)
{
    int size = na_size(nb2) + 1;
    char *tmp;
    char *result;

    if (!(tmp = malloc(sizeof(char) * size)))
        exit(84);
    for (int i = 0; i < size; i++)
        tmp[i] = -1 * nb2[i];
    result = infin_add(nb1, tmp, base);
    free(tmp);
    return (result);
}
