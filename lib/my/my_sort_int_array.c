/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** Prototype_file
*/

#include "mylib.h"

void my_sort_int_array(int *array, int size)
{
    int *order;
    int stock = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > array[i + 1])
            stock = array[i];
    }
    my_putstr("CA MARCHE PAS");
}
