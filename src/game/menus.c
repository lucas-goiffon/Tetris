/*
** EPITECH PROJECT, 2019
** menus.c
** File description:
** menus
*/

#include "../../include/tetris.h"

void tetris_logo(void)
{
    char **str = my_str_to_word_array_two(TETRIS_LOGO, '\n');
    int x = (COLS - my_strlen(str[0])) / 2;
    int y = 5;

    for (int i = 0; str[i]; i++)
        mvprintw(y + i, x, str[i]);
    refresh();
}

int pause_menu(game_t *game)
{
    char c = 0;
    char **str = my_str_to_word_array_two(PAUSE_MSG, '\n');
    int x = (COLS - my_strlen(str[0])) / 2;
    int y = LINES - my_tablen(str) - 5;

    while (c != game->flags->key_pause && c != game->flags->key_quit) {
        c = getch();
        for (int i = 0; str[i]; i++)
            mvprintw(y + i, x, str[i]);
        refresh();
    }
    clear();
    game->info->time_base = time(NULL) - game->info->time_elapsed;
    if (c == game->flags->key_quit)
        return (1);
    return (0);
}

int end_menu(game_t *game)
{
    char c = -1;
    char **str = my_str_to_word_array_two(LOSE_MSG, '\n');
    int x = (COLS - my_strlen(str[0])) / 2;
    int y = LINES - my_tablen(str) - 5;

    while (c == -1) {
        c = getch();
        for (int i = 0; str[i]; i++)
            mvprintw(y + i, x, str[i]);
        mvprintw(y + my_tablen(str), (COLS - 50) / 2,
        "Press space to restart of any other key to quit !");
        refresh();
    }
    clear();
    if (c == ' ')
        return (1);
    return (0);
}