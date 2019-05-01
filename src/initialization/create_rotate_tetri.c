/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** create_rotate_tetri
*/

#include "../../include/tetris.h"

char **create_rotate_tetri(char **tetri, int width, int height)
{
    char **r_tetri = malloc(sizeof(char *) * (width + 1));

    for (int i = 0; i < width; i++) {
        r_tetri[i] = malloc(sizeof(char) * (height + 1));
        fill_str(r_tetri[i], height + 1);
    }
    r_tetri[width] = NULL;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            (tetri[y][x] == '*') ? (r_tetri[x][height - 1 - y] = tetri[y][x]) :
            (r_tetri[x][height - 1 - y] = ' ');
        }
    }
    return (r_tetri);
}