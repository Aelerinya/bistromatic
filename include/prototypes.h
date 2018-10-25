/*
** EPITECH PROJECT, 2018
** prototypes
** File description:
** Prototypes of the functions of the bistromatic
*/

#define MAX(v1, v2) (((v1) > (v2)) ? (v1) : (v2))
#define ABS(v) (((v) > 0) ? (v) : -1 * (v))

char base_to_number(char digit, char *base);
char number_to_base(char nbr, char *base);
char *number_str_to_array(char *str, char *base);
void print_number_array(char *nbr_array, char *base);
int my_strlen_nbr(char *str, char *base);
int na_size(char *num_array);
void remove_trailing_zeros(char *nbr_array);
char *infin_add(char *nb1, char *nb2, char *base);
char *infin_mul(char *nb1, char *nb2, char *base);
