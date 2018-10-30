/*
** EPITECH PROJECT, 2018
** test_errors.c
** File description:
** unit tests for errors.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_ops, wrong_number_of_operators, .exit_code = 84, .init = redirect_all_std)
{
    char nb1[8] = {'(', ')', '+', '-', '*', '/', '%', '+'};
    check_ops(nb1);

    cr_assert_stderr_eq_str("syntax error");
}

Test(check_parenthesis, wrong_number_of_parenthesis, .exit_code = 84, .init = redirect_all_std)
{
    char nb1[9] = {'(', 2, 4, '(', 6, 7, ')', 8, 9};
    char nb2[7] = {'(', ')', '+', '-', '*', '/', '%'};
    check_parenthesis(nb1, nb2);

    cr_assert_stderr_eq_str("syntax error");
}

Test(check_base, wrong_number_of_base, .exit_code = 84, .init = redirect_all_std)
{
    char nb1[1] = {0};
    char nb2[7] = {'(', ')', '+', '-', '*', '/', '%'};
    check_base(nb1, nb2);

    cr_assert_stderr_eq_str("syntax error");
}

Test(check_base, same_base_twice, .exit_code = 84, .init = redirect_all_std)
{
    char nb1[8] = {0, 1, 2, 3, 4, 5, 3, 6};
    char nb2[7] = {'(', ')', '+', '-', '*', '/', '%'};
    check_base(nb1, nb2);

    cr_assert_stderr_eq_str("syntax error");
}

Test(check_duplicate, two_same_operators, .exit_code = 84, .init = redirect_all_std)
{
    char nb1[7] = {'(', ')', '+', '-', '*', '/', '+'};
    check_duplicate(nb1);

    cr_assert_stderr_eq_str("syntax error");
}
