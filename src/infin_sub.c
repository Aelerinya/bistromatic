/*
** EPITECH PROJECT, 2018
** Infin_sub
** File description:
** Substract two number arrays
*/

#include "prototypes.h"

char *infin_sub(char *nb1, char *nb2, char *base)
{
    int size = na_size(nb2);
    
    for (int i = 0; i < size; i++)
        nb2[i] *= -1;
    return (infin_add(nb1, nb2, base));
}
