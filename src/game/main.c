/*
** EPITECH PROJECT, 2019
** main_game.c
** File description:
** main_game
*/

#include "../../include/tetris.h"

void term_size_error(game_t *game)
{
    while (game->flags->map_size.row + 10 > LINES ||
        game->flags->map_size.col + 35 +
        game->info->size_max_tetri * 2 + 2 > COLS) {
        mvprintw(0, 0, "Terminal too small");
        refresh();
    }
}

void analyse_keys(game_t *game, char *c, int width)
{
    if (*c == game->flags->key_right &&
        game->info->co_tetri.x + width < game->flags->map_size.col &&
        tetri_can_move(game, 1, 0))
        game->info->co_tetri.x += 1;
    if (*c == game->flags->key_left && game->info->co_tetri.x > 0 &&
        tetri_can_move(game, -1, 0))
        game->info->co_tetri.x -= 1;
    if (*c == game->flags->key_drop)
        game->info->drop_mode = 1;
    if (*c == game->flags->key_turn)
        turn_tetri(game);
}

int analyse_event(game_t *game, char *c)
{
    int width = -1;

    (game->info->dir_tetri % 2 == 0) ? (width = game->info->cr_tetri->width) :
    (width = game->info->cr_tetri->height);
    *c = getch();
    analyse_keys(game, c, width);
    if (*c == game->flags->key_pause)
        if (pause_menu(game))
            return (1);
    move_tetri(game);
    complete_lines(game);
    if (game->info->score > game->info->high_score)
        game->info->high_score = game->info->score;
    return (0);
}

int game_loop(game_t *game)
{
    char c = 0;

    initialization_game_loop(game);
    while (c != game->flags->key_quit && !game->info->lose) {
        term_size_error(game);
        display_game(game);
        if (analyse_event(game, &c))
            c = game->flags->key_quit;
        refresh_all(game);
    }
    write_highscore(game->info->high_score);
    delwin(game->win->game);
    delwin(game->win->stats);
    delwin(game->win->next);
    if (end_menu(game)) {
        initialization_info(game);
        game_loop(game);
    }
    endwin();
    return (0);
}