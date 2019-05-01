/*
** EPITECH PROJECT, 2019
** init_flags.c
** File description:
** init_flags
*/

#include "../../include/tetris.h"

int init_flags_struct(game_t *game)
{
    if ((game->flags = malloc(sizeof(flags_t))) == NULL)
        return (84);
    game->flags->level = 1;
    game->flags->key_left = 4;
    game->flags->key_right = 5;
    game->flags->key_turn = 3;
    game->flags->key_drop = 2;
    game->flags->key_quit = 'q';
    game->flags->key_pause = ' ';
    game->flags->map_size.row = 20;
    game->flags->map_size.col = 10;
    game->flags->without_next = 0;
    game->flags->debug = 0;
    return (0);
}