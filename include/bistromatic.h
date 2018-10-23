/*
** EPITECH PROJECT, 2018
** Bistromatic header
** File description:
** Header for the bistromatic with error codes, operation codes and prototypes
*/

enum {OP_OPEN_PARENT_IDX, OP_CLOSE_PARENT_IDX, OP_PLUS_IDX, OP_SUB_IDX,
OP_NEG_IDX, OP_MULT_IDX, OP_DIV_IDX, OP_MOD_IDX};

char const *SYNTAX_ERROR_MSG = "syntax error";
char const *ERROR_MSG = "error";

char *eval_expr(char const *base, char const *ops,
char const *expr, unsigned int size);
