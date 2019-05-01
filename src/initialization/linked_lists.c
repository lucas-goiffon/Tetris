/*
** EPITECH PROJECT, 2018
** linked_lists.c
** File description:
** basics functions for linked_lists
*/

#include "../../include/tetris.h"

t_element *insertion_end(t_list *list, char *str)
{
    t_element *new = my_malloc(sizeof(*new));
    new->name = my_malloc(sizeof(char) * (my_strlen(str) + 1));
    new->name = my_strcpy(new->name, str);
    new->width = 0;
    new->height = 0;
    new->color_code = 0;
    new->tetri = my_malloc(sizeof(char **) * 5);
    for (int i = 0; i < 5; i = i + 1)
        new->tetri[i] = NULL;
    if (list->first == NULL && list->last == NULL) {
        new->prev = NULL;
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else {
        new->prev = list->last;
        list->last->next = new;
        new->next = NULL;
        list->last = new;
    } list->lenght = list->lenght + 1;
    return (new);
}

void print_list(t_list *list)
{
    t_element *actual;

    actual = list->first;
    my_printf("Tetriminos : %d\n", list->lenght);
    while (actual != NULL) {
        actual->name[my_strlen(actual->name) - 10] = '\0';
        if (actual->is_error == 0) {
            my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
            actual->name, actual->width, actual->height, actual->color_code);
            print_double_array(actual->tetri[0]);
        } else
            my_printf("Tetriminos : Name %s : Error\n", actual->name);
        actual = actual->next;
    }
}

void destroy_ll(t_list *list)
{
    t_element *actual;
    t_element *next;

    actual = list->first;
    while (actual != NULL) {
        next = actual->next;
        if (actual->name != NULL)
            free(actual->name);
        for (int i = 0; actual->tetri[i] != NULL && i < 4; i++)
            destroy_double_array(actual->tetri[i]);
        free(actual);
        actual = next;
    }
    free(list);
}

t_list *initialisation_empty(void)
{
    t_list *list = my_malloc(sizeof(*list));

    if (list == NULL)
        return (NULL);
    list->first = NULL;
    list->last = NULL;
    list->lenght = 0;
    return (list);
}

void delete_middle(t_list *list, t_element *to_delete)
{
    if (to_delete == list->first) {
        to_delete->next->prev = NULL;
        list->first = to_delete->next;
    } else if (to_delete == list->last) {
        to_delete = list->last;
        to_delete->prev->next = NULL;
        list->last = to_delete->prev;
    } else {
        to_delete->next->prev = to_delete->prev;
        to_delete->prev->next = to_delete->next;
    }
    list->lenght = list->lenght - 1;
    if (to_delete->name != NULL)
        free(to_delete->name);
    if (to_delete->tetri[0] != NULL)
        destroy_double_array(to_delete->tetri[0]);
    free(to_delete);
}