/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main
*/

#include "../include/tetris.h"

void end_destroys(game_t *game)
{
    destroy_ll(game->list);
    free(game->win);
    free(game->flags);
    free(game);
}

int main_next(game_t *game)
{
    if (game->flags->debug == 1)
        print_debug(game->list, game);
    if (game->flags->map_size.col < 5 || game->flags->map_size.row < 5)
        return (84);
    if (initialization_info(game) == 84)
        return (-1);
    return (0);
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    int gf = 0;
    int r = 0;

    game->list = initialisation_empty();
    if (!game || init_flags_struct(game) ||
    (gf = get_flags_tetris(ac, av, game)) == 84)
        return (84);
    else if (gf == -1)
        return (0);
    if (read_directory(game->list) == 84 ||
    open_tetriminos(game, game->list) == 84)
        return (84);
    if ((gf = main_next(game)) == 84)
        return (84);
    else if (gf == -1)
        return (0);
    r = game_loop(game);
    end_destroys(game);
    return (r);
}