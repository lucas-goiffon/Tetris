/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** verify_tetriminos
*/

#include "../../include/tetris.h"

void set_rotated_tetri(t_element *actual)
{
    actual->tetri[1] = create_rotate_tetri(actual->tetri[0], actual->width,
    actual->height);
    actual->tetri[2] = create_rotate_tetri(actual->tetri[1], actual->height,
    actual->width);
    actual->tetri[3] = create_rotate_tetri(actual->tetri[2], actual->width,
    actual->height);
    actual->tetri[4] = NULL;
}

void set_tetri(t_element *actual, int fd)
{
    int j = 0;

    actual->tetri[0] = my_malloc(sizeof(char *) * (actual->height + 1));
    for (int i = 0; i < actual->height; i = i + 1) {
        actual->tetri[0][i] = get_next_line(fd);
        if (actual->tetri[0][i] == NULL) {
            actual->is_error = 1;
            return;
        } j = my_strlen(actual->tetri[0][i]);
        for (j = j - 1; j > 0 && actual->tetri[0][i][j] == ' '; j = j - 1);
        j = j + 1;
        actual->tetri[0][i][j] = '\0';
        if (my_strlen(actual->tetri[0][i]) > actual->width)
            actual->is_error = 1;
    }
    if (get_next_line(fd) != NULL)
        actual->is_error = 1;
    actual->tetri[0][actual->height] = NULL;
    if (actual->is_error == 0)
        set_rotated_tetri(actual);
}

int tetri_is_error(game_t *g, t_list *list, t_element *actual,
char **first_line)
{
    if (my_strlen(first_line[0]) > 10 || is_digits(first_line[0]) != 0 ||
    (actual->width = my_getnbr(first_line[0])) <= 0 ||
    (actual->width > g->flags->map_size.col) ||
    my_strlen(first_line[1]) > 10 || is_digits(first_line[1]) != 0 ||
    (actual->height = my_getnbr(first_line[1])) <= 0 ||
    (actual->height > g->flags->map_size.row) ||
    my_strlen(first_line[2]) > 10 || is_digits(first_line[2]) != 0 ||
    (actual->color_code = my_getnbr(first_line[2])) <= 0) {
        actual->is_error = 1;
        return (84);
    }
    return (0);
}

int verify_tetriminos(game_t *g, t_list *list, t_element *actual, int fd)
{
    char *str = get_next_line(fd);
    char **first_line;

    if (str == NULL) {
        actual->is_error = 1;
        return (0);
    }
    first_line = my_str_to_word_array(str);
    free(str);
    if (my_tablen(first_line) != 3) {
        actual->is_error = 1;
        destroy_double_array(first_line);
        return (0);
    }
    actual->is_error = 0;
    if (tetri_is_error(g, list, actual, first_line) != 84)
        set_tetri(actual, fd);
    destroy_double_array(first_line);
    return (0);
}