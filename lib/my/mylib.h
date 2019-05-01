/*
** EPITECH PROJECT, 2018
** mylib.h
** File description:
** Task02 of CPool Day09
*/

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_nbr_error(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prind_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *concat_params(int argc, char **argv);
int option_printf(char const *format, int *z, va_list ap, ...);
int my_printf(char const *format, ...);
int s_low_flag(char const *format, int *i, va_list ap);
int d_and_i_flags(char const *format, int *i, va_list ap);
int u_flag(char const *format, int *i, va_list ap);
int ld_flag(char const *format, int *i, va_list ap);
int c_flag(char const *format, int *i, va_list ap);
int p_flag(char const *format, int *i, va_list ap);
int x_low_flag(char const *format, int *i, va_list ap);
int x_upp_flag(char const *format, int *i, va_list ap);
int b_flag(char const *format, int *i, va_list ap);
int o_flag(char const *format, int *i, va_list ap);
int s_upp_call_flag(char const *format, int *i, va_list ap);
int mod_flag(char const *format, int *i, va_list ap);
int b_flag(char const *format, int *i, va_list ap);
int s_upp_flag(char *str);
int binary_conversion(unsigned long nb);
void binary_conversion_two(int r, char *str, int char_size);
int hexa_conversion_upp(unsigned long nb);
void hexa_conversion_upp_two(int r, char *str, int char_size);
int hexa_conversion_low(unsigned long nb);
void hexa_conversion_low_two(int r, char *str, int char_size);
int octal_conversion(unsigned long nb);
void octal_conversion_two(int r, char *str, int char_size);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_long_nbr(long int nb);
int my_put_pointer(void *pointer);
int nbsign_flag(char const *format, int *i, va_list ap);
int nbsign_flag_two(char const *format, int *i, va_list ap);
int spaces_delete_printf(char const *format, int *i, va_list ap);
int my_put_short_nbr(short int nb);
int hd_flag(char const *format, int *i, va_list ap);
int octal_conversion_s_upp(unsigned long nb);
char *my_int_to_str(int nb);
void fill_str(char *str, int size);
void fill_str_two(char *str, int size, char to_replace);
char *my_strcat_two(char *dest, char const *src);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_two(char const *str, char sep);
char *get_next_line(int fd);
char *my_strcat_for_gnl(char *dest, char const *src);
int my_strlen_for_gnl(char const *str);
void fill_str_gnl(char *str, int size, char to_replace);
void destroy_double_array(char **array);
int is_digits(char *str);
int is_alpha(char *str);
void *my_malloc(size_t size);
int my_tablen(char **array);
void print_double_array(char **array);
int my_strcmp_maj(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);

#endif
