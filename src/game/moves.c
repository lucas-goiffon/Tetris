/*
** EPITECH PROJECT, 2019
** moves.c
** File description:
** moves
*/

#include "../../include/tetris.h"

int tetri_can_move_next(game_t *game, int mx, int my, int y)
{
    for (int x = 0; game->info->cr_tetri->tetri[game->info->dir_tetri][y][x];
    x++) {
        if (game->info->cr_tetri->tetri[game->info->dir_tetri][y][x] == '*' &&
            game->info->co_tetri.y + y + my >= 0 &&
            game->info->buff_game[game->info->co_tetri.y + y + my]
            [game->info->co_tetri.x + x + mx] != ' ')
            return (0);
    }
    return (1);
}

int tetri_can_move(game_t *game, int mx, int my)
{
    for (int y = 0; game->info->cr_tetri->tetri[game->info->dir_tetri][y]; y++)
        if (!tetri_can_move_next(game, mx, my, y))
            return (0);
    return (1);
}

void tetri_dont_move(game_t *game)
{
    write_buff_game(game->info, &game->info->co_tetri);
    game->info->cr_tetri = game->info->nx_tetri;
    game->info->nx_tetri = rand_tetri(game->list, rand() % game->list->lenght);
    game->info->co_tetri.y = -game->info->cr_tetri->height;
    game->info->co_tetri.x = game->flags->map_size.col / 2 -
    game->info->cr_tetri->width / 2;
    if (game->info->drop_mode)
        game->info->drop_mode = 0;
    game->info->dir_tetri = 0;
    game->info->score += 2 * game->flags->level;
}

void move_tetri(game_t *game)
{
    static int timer = 0;

    if (timer > 300 / game->flags->level || game->info->drop_mode) {
        timer = -1;
        if (game->info->co_tetri.y +
            my_tablen(game->info->cr_tetri->tetri[game->info->dir_tetri]) <
            game->flags->map_size.row && tetri_can_move(game, 0, 1))
            game->info->co_tetri.y += 1;
        else if (game->info->co_tetri.y <= 0)
            game->info->lose = 1;
        else
            tetri_dont_move(game);
    }
    timer++;
}