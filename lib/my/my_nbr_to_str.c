/*
** EPITECH PROJECT, 2018
** my_nbr_to_str
** File description:
** Convert an int into a string
*/

#include <stdlib.h>

static void convertor(int nb, char *str)
{
    char leading_zeros = 1;
    int digit;
    int power = 1000000000;
    int pos = 0;

    for (char digit_pos = 9; digit_pos >= 0; digit_pos--) {
        digit = nb / power;
        nb = nb % power;
        power = power / 10;
        if (leading_zeros == 1 && digit != 0) {
            leading_zeros = 0;
        }
        if (leading_zeros == 0) {
            str[pos] = digit + 48;
            pos++;
        }
    }
    str[pos] = '\0';
}

char *my_nbr_to_str(int nb)
{
    char *str;

    str = malloc(sizeof(char) * 12);
    if (nb == 0) {
        return ("0");
    } else if (nb == -2147483648) {
        return ("-2147483648");
    } else {
        if (nb < 0) {
            str[0] = '-';
            nb = -nb;
            convertor(nb, str + 1);
        } else
            convertor(nb, str);
    }
    return (str);
}
