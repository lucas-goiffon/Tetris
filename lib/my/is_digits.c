/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** is_digits
*/

#include "mylib.h"

int is_digits(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 48 || str[i] > 57)
            return (84);
    }
    return (0);
}