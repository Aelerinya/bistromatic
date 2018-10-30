/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** Fork from the CPool project eval_expr : adaptation to number arrays.
*/

#include "../lib/my/my.h"
#include "../include/prototypes.h"
#include <stdlib.h>
#include <unistd.h>

char *my_strtol(char **str, char *base, char *op)
{
    char neg = 1;
    char *nbr_array;
    int size;

    for (neg = 1; **str == op[OP_SUB] || **str == op[OP_ADD]; (*str)++)
        if (**str == op[OP_SUB])
            neg *= -1;
    size = my_strlen_nbr((*str), base);
    if (size <= 0)
        exit(84);
    nbr_array = malloc(sizeof(char) * (size + 2));
    for (int i = 0; i < size; i++) {
        nbr_array[size - i - 1] = neg * base_to_number(**str, base);
        (*str)++;
    }
    nbr_array[size] = (size) ? -128 : 0;
    nbr_array[size + 1] = -128;
    return nbr_array;
}

char *summands(char **str, char *base, char *op)
{
    char *sum = parenthesis(str, base, op);

    if (**str == op[OP_MUL] || **str == op[OP_DIV] || **str == op[OP_MOD])
        sum = factors(str, sum, base, op);
    if (**str == '\0' || **str == op[OP_CLOSEP])
        return (sum);
    if (**str == op[OP_ADD] || **str == op[OP_SUB])
        return infin_add(sum, summands(str, base, op), base);
    my_putchar(**str);
    write(2, "Invalid operator\n", 17);
    exit(84);
}

char *factors(char **str, char *fac, char *base, char *op)
{
    char tmp = **str;
    char *result;
    char *next;

    while (tmp == op[OP_MUL] || tmp == op[OP_DIV] || tmp == op[OP_MOD]) {
        (*str)++;
        next = parenthesis(str, base, op);
        if (tmp == op[OP_MUL])
            result = infin_mul(fac, next, base);
        if (tmp == op[OP_DIV])
            result = infin_div(fac, next, base);
        if (tmp == op[OP_MOD])
            result = infin_mod(fac, next, base);
        tmp = **str;
        fac = result;
    }
    return (result);
}

char *parenthesis(char **str, char *base, char *op)
{
    int neg = (**str == op[OP_SUB]) ? -1 : 1;
    char *result;

    if ((neg == -1 || **str == op[OP_ADD]) && (*str)[1] == op[OP_OPENP])
        (*str)++;
    if (**str == op[OP_OPENP]) {
        (*str)++;
        result = summands(str, base, op);
        if (neg == -1)
            for (int i = 0; result[i] != -128; i++)
                result[i] *= -1;
        (*str)++;
    } else {
        result = my_strtol(str, base, op);
    }
    return result;
}

char *eval_expr(char *str, char *base, char *op)
{
    return summands(&str, base, op);
}