/*
** EPITECH PROJECT, 2018
** pushswap.c
** File description:
** Main file for PushSwap project
*/

#include "../../include/tetris.h"

void sort(t_list *l_a, t_list *l_b)
{
    t_element *actual = l_a->first->next;
    char *stock;
    int scount = 0;

    stock = l_a->first->name;
    for (int i = 1; actual != NULL; i = i + 1) {
        if (my_strcmp(actual->name, stock) <= 0) {
            stock = actual->name;
            scount = i;
        }
        actual = actual->next;
    }
    for (int i = 0; i < scount; i = i + 1)
        rotate_r(l_a);
    exchange_p(l_a, l_b);
    scount = 0;
    actual = l_a->first;
    if (l_a->lenght > 0)
        sort(l_a, l_b);
}

void end_sort(t_list *l_a, t_list *l_b)
{
    int lenght = 0;
    int ssize = 0;

    lenght = l_b->lenght;
    while (ssize < lenght) {
        exchange_p(l_b, l_a);
        ssize = ssize + 1;
    }
}

void sort_alpha(t_list *l_a)
{
    t_list *l_b = initialisation_empty();

    sort(l_a, l_b);
    end_sort(l_a, l_b);
    free(l_b);
}
