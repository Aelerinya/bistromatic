/*
** EPITECH PROJECT, 2018
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
    int size = na_size(nb1) + 1;
    char neg1 = remove_negatives(nb1);
    char neg2 = remove_negatives(nb2);
    int start = find_starting_index(nb1, nb2);

    result = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        result[i] = 0;
    for (int j = start; j >= 0; j--) {
        divide_pos(result + start - j, nb1 + j, nb2, base);
        remove_trailing_zeros(nb1);
    }
    result[size - 1] = -128;
    for (int k = 0; result[k] != -128; k++)
        result[k] *= neg1 * neg2;
    for (int l = 0; nb1[l] != -128 && neg1 == -1; l++)
        nb1[l] *= neg1;
    remove_trailing_zeros(result);
    reverse_number_array(result);
    return (result);
}

void divide_pos(char *result, char *nb1, char *nb2, char *base)
{
    char *new;
    int k;

    while (infin_compare(nb1, nb2) != -1) {
        (*result)++;
        new = infin_sub(nb1, nb2, base);
        for (k = 0; new[k] != -128; k++)
            nb1[k] = new[k];
        nb1[k] = -128;
        free(new);
    }
}

int find_starting_index(char *nb1, char *nb2)
{
    char *copy;
    int start = 0;

    if (nb2[0] == 0 && nb2[1] == -128)
        exit(84);
    if (!(copy = malloc(sizeof(char) * (MAX(na_size(nb1), na_size(nb2)) + 1))))
        exit(84);
    for (int i = 0; i <= na_size(nb2); i++)
        copy[i] = nb2[i];
    for (start = 0; infin_compare(nb1 + start, copy) != -1; start++);
    free(copy);
    return (start - 1);
}

void reverse_number_array(char *nbr_array)
{
    int length = na_size(nbr_array);
    char swap;

    for (int i = 0; i < length / 2; i++) {
        swap = nbr_array[length - i - 1];
        nbr_array[length - i - 1] = nbr_array[i];
        nbr_array[i] = swap;
    }
}

char remove_negatives(char *nb)
{
    int neg = 1;

    for (int j = 0; nb[j] != -128; j++) {
        neg = (nb[j] < 0) ? -1 : 1;
        nb[j] = ABS(nb[j]);
    }
    return (neg);
}
