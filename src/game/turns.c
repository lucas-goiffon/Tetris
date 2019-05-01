/*
** EPITECH PROJECT, 2019
** turns.c
** File description:
** turns
*/

#include "../../include/tetris.h"

int tetri_can_turn_next(game_t *game, int y, int dir)
{
    for (int x = 0; game->info->cr_tetri->tetri[dir][y][x]; x++) {
        if (game->info->co_tetri.y + y >= my_tablen(game->info->buff_game))
            return (0);
        else if (game->info->co_tetri.y + y >= 0 &&
            game->info->buff_game[game->info->co_tetri.y + y]
            [game->info->co_tetri.x + x] != ' ' &&
            game->info->cr_tetri->tetri[dir][y][x] == '*')
            return (0);
    }
    return (1);
}

int tetri_can_turn(game_t *game)
{
    int dir = -1;

    if (game->info->dir_tetri < 3)
        dir = game->info->dir_tetri + 1;
    else
        dir = 0;
    for (int y = 0; game->info->cr_tetri->tetri[dir][y]; y++)
        tetri_can_turn_next(game, y, dir);
    return (1);
}

void turn_tetri(game_t *game)
{
    int width = -1;

    if (!tetri_can_turn(game))
        return;
    (game->info->dir_tetri % 2 == 0) ? (width = game->info->cr_tetri->height)
    : (width = game->info->cr_tetri->width);
    if (game->info->dir_tetri < 3)
        game->info->dir_tetri += 1;
    else
        game->info->dir_tetri = 0;
    if (game->info->co_tetri.x + width >= game->flags->map_size.col)
        game->info->co_tetri.x = game->flags->map_size.col - width;
}