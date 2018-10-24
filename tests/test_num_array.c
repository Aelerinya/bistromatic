/*
** EPITECH PROJECT, 2018
** Tests num_array
** File description:
** Tests for the functions manipulating number arrays
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "prototypes.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(number_str_to_array, normal)
{
    char theory[8] = {10, 0, 7, 15, 14, 1, 11, -128};
    char *result = number_str_to_array("B1EF70A", "0123456789ABCDEF");

    for (int i = 0; i < 8; i++)
        cr_assert_eq(theory[i], result[i]);
}

Test(number_str_to_array, empty)
{
    char theory[2] = {0, -128};
    char *result = number_str_to_array("", "0123456789ABCDEF");

    for (int i = 0; i < 2; i++)
        cr_assert_eq(theory[i], result[i]);
}

Test(print_number_array, normal, .init = redirect_all_std)
{
    char array[8] = {10, 0, 7, 15, 14, 1, 11, -128};

    print_number_array(array, "0123456789ABCDEF");
    fflush(stdout);
    cr_assert_stdout_eq_str("B1EF70A\n");
}

Test(my_strlen_nbr, normal)
{
    cr_assert_eq(my_strlen_nbr("2120200212132120", "012"), 11);
    cr_assert_eq(my_strlen_nbr("2120200212132120", "abc"), 0);
}

Test(na_size, normal)
{
    char array1[8] = {10, 0, 7, 15, 14, 1, 11, -128};
    char array2[1] = {-128};

    cr_assert_eq(na_size(array1), 7);
    cr_assert_eq(na_size(array2), 0);
}
