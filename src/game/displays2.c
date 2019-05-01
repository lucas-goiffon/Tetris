/*
** EPITECH PROJECT, 2019
** displays2.c
** File description:
** displays2
*/

#include "../../include/tetris.h"

char *print_minutes(time_t seconds)
{
    char *min = my_int_to_str(seconds / 60);
    char *sec = my_int_to_str(seconds % 60);
    int place = 1 + my_strlen(min);
    char *res = "   ";

    if ((seconds / 60) >= 1) {
        res = my_strcat_two(res, min);
        res = my_strcat_two(res, "min ");
        res = my_strcat_two(res, sec);
        res = my_strcat_two(res, "s");
    } else {
        res = my_strcat_two(res, sec);
        if ((seconds % 60) != 0)
            res = my_strcat_two(res, "s");
    }
    return (res);
}

void display_stats(game_t *game)
{
    game->info->time_elapsed =
    (time(&game->info->time_elapsed)) - game->info->time_base;
    mvwprintw(game->win->stats, 2, 2, "High Score:");
    mvwprintw(game->win->stats, 2, 28 - my_strlen(my_int_to_str(
    game->info->high_score)), "%d", game->info->high_score);
    mvwprintw(game->win->stats, 3, 2, "Score:");
    mvwprintw(game->win->stats, 3,
    28 - my_strlen(my_int_to_str(game->info->score)), "%d", game->info->score);
    mvwprintw(game->win->stats, 5, 2, "Lines Completed:");
    mvwprintw(game->win->stats, 5,
    28 - my_strlen(my_int_to_str(game->info->tt_line_del)),
    my_int_to_str(game->info->tt_line_del));
    mvwprintw(game->win->stats, 6, 2, "Level:");
    mvwprintw(game->win->stats, 6,
    28 - my_strlen(my_int_to_str(game->flags->level)), "%d",
    game->flags->level);
    mvwprintw(game->win->stats, 8, 2, "Timer:");
    mvwprintw(game->win->stats, 8,
    28 - my_strlen(print_minutes(game->info->time_elapsed)),
    print_minutes(game->info->time_elapsed));
}

void display_game(game_t *game)
{
    display_buff(game);
    display_tetri(game);
    display_next_tetri(game);
    display_stats(game);
    if ((LINES - game->flags->map_size.row) / 2 > 10)
        tetris_logo();
}

void refresh_all(game_t *game)
{
    box(game->win->game, 0, 0);
    mvwprintw(game->win->game, 0,
    (game->flags->map_size.col * 2 - 6) / 2 + 1, "|Game|");
    wrefresh(game->win->game);
    box(game->win->stats, 0, 0);
    mvwprintw(game->win->stats, 0,
    30 - 8, "|Stats|");
    wrefresh(game->win->stats);
    if (!game->flags->without_next) {
        box(game->win->next, 0, 0);
        mvwprintw(game->win->next, 0, 1, "|Next|");
        wrefresh(game->win->next);
    }
}