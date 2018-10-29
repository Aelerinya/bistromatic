/*
** EPITECH PROJECT, 2018
** test_infin_compare
** File description:
** Unit tests for the function of infin_compare
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(infin_compare, nb1_bigger)
{
    char nb1[4] = {3, 8, 3, -128};
    char nb2[4] = {3, 8, 2, -128};
    char theory[2] = {1, -128};
    int result = infin_compare(nb1, nb2);

    for (int i = 0; theory[i] != -128; i++)
	cr_assert_eq(result, theory[i]);
}

Test(infin_compare, nb2_bigger)
{
    char nb1[4] = {8, 8, 8, -128};
    char nb2[4] = {8, 8, 9, -128};
    char theory[2] = {-1, -128};
    int result = infin_compare(nb1, nb2);

    for (int i = 0; theory[i] != -128; i++)
	cr_assert_eq(result, theory[i]);
}

Test(infin_compare, nb1_2_even)
{
    char nb1[3] = {1, 4, -128};
    char nb2[3] = {1, 4, -128};
    char theory[2] = {0, -128};
    int result = infin_compare(nb1, nb2);

    for (int i = 0; theory[i] != -128; i++)
	cr_assert_eq(result, theory[i]);
}
