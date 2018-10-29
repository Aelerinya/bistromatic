/*
** EPITECH PROJECT, 2018
** Infin_compare
** File description:
** Compares two integers of arbitrary size in number arrays
*/

#include "prototypes.h"

int infin_compare(char *nb1, char *nb2)
{
    int size1 = na_size(nb1);
    int size2 = na_size(nb2);

    if (size1 > size2)
        return (1);
    else if (size1 < size2)
        return (-1);
    for (int i = size1 - 1; i >= 0; i--) {
        if (nb1[i] > nb2[i])
            return (1);
        else if (nb1[i] < nb2[i])
            return (-1);       
    }
    return (0);
}
