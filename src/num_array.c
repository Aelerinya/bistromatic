/*
** EPITECH PROJECT, 2018
** Utilities to manipulate bases
** File description:
** Utilities to manipulate bases and convert to and from number arrays
*/

#include "my.h"
#include "prototypes.h"
#include <stdlib.h>

char *number_str_to_array(char *str, char *base)
{
    char neg = 1;
    char *nbr_array;
    int size;

    for (neg = 1; *str == '-' || *str == '+'; str++)
        if (*str == '-')
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

void print_number_array(char *nbr_array, char *base)
{
    char digit;
    int size;
    int neg;

    for (int j = 0; nbr_array[j] != -128; j++)
        neg = (nbr_array[j] < 0) ? -1 : 1;
    for (size = 0; nbr_array[size] != -128; size++);
    if (neg == -1)
        my_putchar('-');
    for (int i = size - 1; i >= 0; i--) {
        digit = number_to_base(neg * nbr_array[i], base);
        my_putchar(digit);
    }
    my_putchar('\n');
}

int my_strlen_nbr(char *str, char *base)
{
    int size;

    for (size = 0; base_to_number(str[size], base) != -1; size++);
    return size;
}
