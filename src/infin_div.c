/*
65;5402;1c** EPITECH PROJECT, 2018
** Infin_div
** File description:
** Function that divide a number array by another in the given base
*/

#include "my.h"
#include "prototypes.h"
#include <stdlib.h>

char *infin_div(char *nb1, char *nb2, char *base)
{
    char *result;
    int start;
    int size = na_size(nb1) + 1;

    if (!(result = malloc(sizeof(char) * size)))
        exit(84);
    for (int i = 0; i < size; i++)
        result[i] = 0;
    start = find_starting_index(nb1, nb2, base);
    return (result);
}

int find_starting_index(char *nb1, char *nb2)
{
    char *copy;
    int start = 0;
    int neg = 1;

    for (int j = 0; nb1[j] != -128; j++)
        neg = (nb1[j] < 0) ? -1 : 1;
    if (!(copy = malloc(sizeof(char) * (na_size(nb1) + 1))))
        exit(84);
    for (int i = 0; i <= na_size(nb2); i++)
        copy[i] = neg * ABS(nb2[i]);
    while (infin_compare(nb1, copy) != neg * -1) {
        start++;
        for (int j = na_size(copy); j >= 0; j--)
            copy[j + 1] = copy[j];
        copy[0] = 0;
    }
    return (start - 1);
}
