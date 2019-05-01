/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** my_malloc
*/

#include "mylib.h"

void *my_malloc(size_t size)
{
    void *to_alloc = malloc(size);

    if (to_alloc == NULL)
        exit(84);
    return (to_alloc);
}