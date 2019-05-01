/*
** EPITECH PROJECT, 2019
** write_buff_game.c
** File description:
** write_buff_game
*/

#include "../../include/tetris.h"

void write_buff_game(info_t *info, coords_t *coords)
{
    for (int y = 0; info->cr_tetri->tetri[info->dir_tetri][y]; y++) {
        for (int x = 0; info->cr_tetri->tetri[info->dir_tetri][y][x]; x++) {
            (info->cr_tetri->tetri[info->dir_tetri][y][x] == '*' &&
            coords->y + y >= 0) ? (info->buff_game[coords->y + y][coords->x + x]
            = (char)info->cr_tetri->color_code) : (0);
        }
    }
}