/*
** EPITECH PROJECT, 2019
** rand_tetri.c
** File description:
** rand_tetri
*/

#include "../../include/tetris.h"

t_element *rand_tetri(t_list *list, int choise)
{
    int i = 0;
    t_element *elem = list->first;

    while (elem && i < choise) {
        elem = elem->next;
        i++;
    }
    return (elem);
}