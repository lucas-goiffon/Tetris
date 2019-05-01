/*
** EPITECH PROJECT, 2019
** initialization_info.c
** File description:
** initialization_info
*/

#include "../../include/tetris.h"

void initialization_info_buff(game_t *game)
{
    game->info->buff_game = my_malloc(sizeof(char *) *
    (game->flags->map_size.row + 1));
    for (int y = 0; y < game->flags->map_size.row; y++) {
        game->info->buff_game[y] = my_malloc(sizeof(char) *
        game->flags->map_size.col + 1);
        fill_str(game->info->buff_game[y], sizeof(char) *
        game->flags->map_size.col + 1);
        for (int x = 0; x < game->flags->map_size.col; x++) {
            game->info->buff_game[y][x] = ' ';
        }
    }
    game->info->buff_game[game->flags->map_size.row] = NULL;
}

void clean_list(t_list *list)
{
    t_element *elem = list->first;
    t_element *prev_elem = NULL;

    while (elem) {
        if (elem->is_error) {
            (prev_elem) ? (prev_elem->next = elem->next) : (0);
            (elem->next) ? (elem->next->prev = prev_elem) : (0);
            list->lenght -= 1;
        }
        prev_elem = elem;
        elem = elem->next;
    }
}

void initialization_info_next(game_t *game)
{
    game->info->pause = 0;
    game->info->lose = 0;
    game->info->drop_mode = 0;
    game->info->line_del = 0;
    game->info->tt_line_del = 0;
    game->info->co_tetri.x = 0;
    game->info->co_tetri.y = 0;
    game->info->dir_tetri = 0;
    game->info->cr_tetri = rand_tetri(game->list, rand() % game->list->lenght);
    game->info->nx_tetri = rand_tetri(game->list, rand() % game->list->lenght);
    game->info->time_elapsed = time(NULL);
    game->info->time_base = time(&game->info->time_elapsed);
    game->info->size_max_tetri = size_max_tetri(game);
    game->info->score = 0;
    game->info->high_score = read_high_score();
}

int initialization_info(game_t *game)
{
    game->info = my_malloc(sizeof(info_t));
    clean_list(game->list);
    if (game->list->lenght < 1) {
        my_printf("Not enough valid tetriminos\n");
        return (84);
    }
    initialization_info_next(game);
    initialization_info_buff(game);
    return (0);
}