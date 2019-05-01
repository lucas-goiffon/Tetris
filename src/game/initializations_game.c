/*
** EPITECH PROJECT, 2019
** initializations.c
** File description:
** initializations
*/

#include "../../include/tetris.h"

void initialization_colors(void)
{
    start_color();
    assume_default_colors(COLOR_WHITE, COLOR_BLACK);
    init_color(COLOR_ORANGE, 800, 400, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_ORANGE, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(42, COLOR_WHITE, COLOR_WHITE);
}

void initialization_windows(game_t *game)
{
    game->win->game = newwin(game->flags->map_size.row + 1,
    game->flags->map_size.col * 2 + 1, (LINES - game->flags->map_size.row) / 2,
    (COLS - game->flags->map_size.col * 2) / 2);
    game->win->stats = newwin(11, 30, (LINES - 11) / 2,
    (COLS - game->flags->map_size.col * 2) / 2 - 34);
    game->win->next = newwin(game->info->size_max_tetri + 4,
    game->info->size_max_tetri * 2 + 4,
    (LINES - (game->info->size_max_tetri + 4)) / 2,
    (COLS - game->flags->map_size.col * 2) / 2 +
    game->flags->map_size.col * 2 + 6);
}

void initialization_game_loop(game_t *game)
{
    srand(time(NULL));
    game->info->co_tetri.x = game->flags->map_size.col / 2 -
    game->info->cr_tetri->width / 2;
    game->info->co_tetri.y = -game->info->cr_tetri->height;
    game->win = malloc(sizeof(windows_t));
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    timeout(1);
    curs_set(0);
    initialization_colors();
    initialization_windows(game);
}