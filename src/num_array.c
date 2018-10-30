/*
** EPITECH PROJECT, 2018
** Utilities to manipulate bases
** File description:
** Utilities to manipulate bases and convert to and from number arrays
*/

#include "my.h"
#include "prototypes.h"
#include <stdlib.h>

char *number_str_to_array(char *str, char *base, char *op)
{
    char neg = 1;
    char *nbr_array;
    int size;

    for (neg = 1; *str == op[OP_SUB] || *str == op[OP_ADD]; str++)
        if (*str == op[OP_SUB])
            neg *= -1;
    size = my_strlen_nbr(str, base);
    nbr_array = malloc(sizeof(char) * (size + 2));
    for (int i = 0; i < size; i++) {
        nbr_array[size - i - 1] = neg * base_to_number(str[i], base);
    }
    nbr_array[size] = (size) ? -128 : 0;
    nbr_array[size + 1] = -128;
    return nbr_array;
}

void print_number_array(char *nbr_array, char *base, char *op)
{
    char digit;
    int size;
    int neg;

    for (int j = 0; nbr_array[j] != -128; j++)
        neg = (nbr_array[j] < 0) ? -1 : 1;
    for (size = 0; nbr_array[size] != -128; size++);
    if (neg == -1)
        my_putchar(op[OP_SUB]);
    for (int i = size - 1; i >= 0; i--) {
        digit = number_to_base(neg * nbr_array[i], base);
        my_putchar(digit);
    }
}

int my_strlen_nbr(char *str, char *base)
{
    int size;

    for (size = 0; base_to_number(str[size], base) != -1; size++);
    return size;
}

int na_size(char *num_array)
{
    int i;

    for (i = 0; num_array[i] != -128; i++);
    return i;
}

void remove_trailing_zeros(char *nbr_array)
{
    int last = 0;

    for (int i = 0; nbr_array[i] != -128; i++)
        if (nbr_array[i] != 0)
            last = i;
    nbr_array[last + 1] = -128;
}
