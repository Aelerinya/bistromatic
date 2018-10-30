/*
** EPITECH PROJECT, 2018
** Infin_mod
** File description:
** Modulo of number arrays
*/

#include "../include/prototypes.h"

char *infin_mod(char *nb1, char *nb2, char *base)
{
    infin_div(nb1, nb2, base);
    return (nb1);
}
