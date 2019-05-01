/*
** EPITECH PROJECT, 2019
** size_max_teri.c
** File description:
** size_max_tetri
*/

#include "../../include/tetris.h"

int size_max_tetri(game_t *g)
{
    t_element *actual = g->list->first;
    int max = 0;

    while (actual != NULL) {
        if (actual->height > max)
            max = actual->height;
        if (actual->width > max)
            max = actual->width;
        actual = actual->next;
    }
    return (max);
}