/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** destroy_double_array
*/

#include "mylib.h"

void destroy_double_array(char **array)
{
    for (int i = 0; array[i] != NULL; i = i + 1)
        free(array[i]);
    free(array);
}