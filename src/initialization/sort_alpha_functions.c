/*
** EPITECH PROJECT, 2018
** main_functions.c
** File description:
** Main fonctions for PushSwap Project (SA, RA, RRA, PA..)
*/

#include "../../include/tetris.h"

void swap_s(t_list *list)
{
    if (list->lenght > 2) {
        list->first->next->next->prev = list->first;
        list->first->next->prev = NULL;
        list->first->prev = list->first->next;
        list->first->next = list->first->next->next;
        list->first->prev->next = list->first;
        list->first = list->first->prev;
    } else if (list->lenght == 2) {
        list->first->prev = list->last;
        list->last->next = list->first;
        list->first = list->last;
        list->last = list->first->next;
        list->first->prev = NULL;
        list->last->next = NULL;
    }
}

void rotate_rr(t_list *list)
{
    if (list->lenght > 1) {
        list->first->prev = list->last;
        list->last = list->last->prev;
        list->last->next = NULL;
        list->first->prev->next = list->first;
        list->first = list->first->prev;
        list->first->prev = NULL;
    }
}

void rotate_r(t_list *list)
{
    if (list->lenght > 1) {
        list->first->prev = list->last;
        list->last->next = list->first;
        list->first->next->prev = NULL;
        list->first = list->first->next;
        list->last = list->last->next;
        list->last->next = NULL;
    }
}

void exchange_p(t_list *src, t_list *dest)
{
    exchange_p_following(src, dest);
    if (src->lenght > 1 && dest->lenght > 0) {
        dest->first->prev = src->first;
        src->first = src->first->next;
        src->first->prev->next = dest->first;
        dest->first = dest->first->prev;
        dest->first->prev = NULL;
        src->first->prev = NULL;
        dest->lenght = dest->lenght + 1;
        src->lenght = src->lenght - 1;
    } else if (src->lenght > 1 && dest->lenght == 0) {
        src->first = src->first->next;
        dest->first = src->first->prev;
        dest->first->next = NULL;
        dest->first->prev = NULL;
        dest->last = dest->first;
        src->first->prev = NULL;
        dest->lenght = dest->lenght + 1;
        src->lenght = src->lenght - 1;
    }
}

void exchange_p_following(t_list *src, t_list *dest)
{
    if (src->lenght == 1 && dest->lenght > 0) {
        dest->first->prev = src->first;
        src->first->next = dest->first;
        src->first = NULL;
        dest->first = dest->first->prev;
        dest->first->prev = NULL;
        src->last = NULL;
        dest->lenght = dest->lenght + 1;
        src->lenght = src->lenght - 1;
    }
}
