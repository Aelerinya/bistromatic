/*
** EPITECH PROJECT, 2018
** Bistromatic header
** File description:
** Header for the bistromatic with error codes, operation codes and prototypes
*/

char const *SYNTAX_ERROR_MSG = "syntax error";
char const *ERROR_MSG = "error";

char *eval_expr(char const *base, char const *ops,
char const *expr, unsigned int size);
