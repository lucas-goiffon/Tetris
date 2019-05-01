/*
** EPITECH PROJECT, 2019
** displays.c
** File description:
** displays
*/

#include "../../include/tetris.h"

void display_char(game_t *game, int x, int y)
{
    if (game->info->buff_game[y][x] != ' ') {
        wattron(game->win->game, COLOR_PAIR(game->info->buff_game[y][x]));
        mvwprintw(game->win->game, y, x * 2 + 1, "*");
        wattroff(game->win->game, COLOR_PAIR(game->info->buff_game[y][x]));
    } else {
        mvwprintw(game->win->game, y, x * 2 + 1, " ");
    }
}

void display_buff(game_t *game)
{
    for (int y = 0; y < game->flags->map_size.row; y++) {
        for (int x = 0; game->info->buff_game[y][x]; x++) {
            mvwprintw(game->win->game, y, x * 2, " ");
            display_char(game, x, y);
        }
    }
}

void display_tetri_next(game_t *game, int x, int y)
{
    if (game->info->co_tetri.y + y + 1 > 0) {
        mvwprintw(game->win->game, game->info->co_tetri.y + y,
        (game->info->co_tetri.x + x) * 2, " ");
        mvwprintw(game->win->game, game->info->co_tetri.y + y,
        (game->info->co_tetri.x + x) * 2 + 1,
        &game->info->cr_tetri->tetri[game->info->dir_tetri][y][x]);
    }
}

void display_tetri(game_t *game)
{
    wattron(game->win->game, COLOR_PAIR(game->info->cr_tetri->color_code));
    for (int y = 0; game->info->cr_tetri->tetri[game->info->dir_tetri][y]; y++)
        for (int x = 0;
        game->info->cr_tetri->tetri[game->info->dir_tetri][y][x]; x++)
            display_tetri_next(game, x, y);
    wattroff(game->win->game, COLOR_PAIR(game->info->cr_tetri->color_code));
}

void display_next_tetri(game_t *game)
{
    for (int y = 1; y < game->info->size_max_tetri + 3; y++)
        for (int x = 1; x < game->info->size_max_tetri * 2 + 3; x++)
            mvwprintw(game->win->next, y, x, " ");
    wattron(game->win->next, COLOR_PAIR(game->info->nx_tetri->color_code));
    for (int y = 0; game->info->nx_tetri->tetri[0][y]; y++) {
        for (int x = 0; game->info->nx_tetri->tetri[0][y][x]; x++) {
            mvwprintw(game->win->next, (game->info->size_max_tetri + 2 -
            game->info->nx_tetri->height) / 2 + y + 1,
            ((game->info->size_max_tetri + 2 -
            game->info->nx_tetri->width) / 2 + x) * 2, " ");
            mvwprintw(game->win->next, (game->info->size_max_tetri + 2 -
            game->info->nx_tetri->height) / 2 + y + 1,
            ((game->info->size_max_tetri + 2 -
            game->info->nx_tetri->width) / 2 + x) * 2 + 1,
            &game->info->nx_tetri->tetri[0][y][x]);
        }
    }
    wattroff(game->win->next, COLOR_PAIR(game->info->nx_tetri->color_code));
}