/*
** EPITECH PROJECT, 2018
** InfinAdd
** File description:
** Working parts of infin add project
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "add.h"
#include "prototypes.h"

static char rec_add(char *result, op_t *op);
static void manage_carry(char *result, int base);

char *infin_add(char *nb1, char *nb2, char *base)
{
    char *result;
    op_t op = {nb1, nb2, 0, my_strlen(base)};

    result = malloc(sizeof(char) * (MAX(na_size(nb1), na_size(nb2)) + 2));
    rec_add(result, &op);
    remove_trailing_zeros(result);
    manage_carry(result, my_strlen(base));
    remove_trailing_zeros(result);
    return (result);
}

static char rec_add(char *result, op_t *op)
{
    if (op->nb1[0] == -128 && op->nb2[0] == -128) {
        *result = (op->carry) ? op->carry : -128;
        *(result + 1) = -128;
        return (0);
    }
    if (op->nb1[0] == -128) {
        *result = (op->nb2[0] + op->carry) % op->base;
        op->carry = (op->nb2[0] + op->carry) / op->base;
        op->nb2++;
    } else if (op->nb2[0] == -128) {
        *result = (op->nb1[0] + op->carry) % op->base;
        op->carry = (op->nb1[0] + op->carry) / op->base;
        op->nb1++;
    } else {
        *result = (op->nb1[0] + op->nb2[0] + op->carry) % op->base;
        op->carry = (op->nb1[0] + op->nb2[0] + op->carry) / op->base;
        op->nb1++;
        op->nb2++;
    }
    rec_add(result + 1, op);
    return (0);
}

static void manage_carry(char *result, int base)
{
    int negative = 0;

    for (int j = 0; result[j] != -128; j++)
        negative = (result[j] < 0) ? 1 : 0;
    for (int i = 0; result[i] != -128; i++) {
        if (result[i] < 0 && !negative) {
            result[i] += base;
            result[i + 1]--;
        } else if (result[i] > 0 && negative) {
            result[i] -= base;
            result[i + 1]++;
        }
    }
}
