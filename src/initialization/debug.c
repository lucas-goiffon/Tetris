/*
** EPITECH PROJECT, 2019
** debug.c
** File description:
** debug
*/

#include "../../include/tetris.h"

char *transform_key(char key)
{
    char *n_key = malloc(sizeof(char) * 2);

    n_key[0] = key;
    n_key[1] = 0;
    return (n_key);
}

char *rtn_key(int key)
{
    if (key > 32 && key < 127)
        return (transform_key(key));
    if (key == 32)
        return ("(space)");
    if (key == 4)
        return ("^EOD");
    if (key == 5)
        return ("^EOC");
    if (key == 2)
        return ("^EOB");
    if (key == 3)
        return ("^EOA");
    return (NULL);
}

int get_key(void)
{
    int c = 0;
    struct timeval tv;

    fd_set fs;
    tv.tv_usec = tv.tv_sec = 0;
    FD_ZERO(&fs);
    FD_SET(STDIN_FILENO, &fs);
    select(STDIN_FILENO + 1, &fs, 0, 0, &tv);
    if (FD_ISSET(STDIN_FILENO, &fs))
        c = getchar();
    return c;
}

void wait_key_pressed(void)
{
    int c;
    struct termios old;
    struct termios new;

    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    while (!(c = get_key()));
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
}

void print_debug(t_list *list, game_t *game)
{
    my_printf("*** DEBUG MODE ***\n");
    my_printf(DEBUG_KEYS_FORMAT,
    rtn_key(game->flags->key_left), rtn_key(game->flags->key_right),
    rtn_key(game->flags->key_turn), rtn_key(game->flags->key_drop),
    rtn_key(game->flags->key_quit), rtn_key(game->flags->key_pause));
    if (game->flags->without_next == 0)
        my_printf("Next : Yes\n");
    else
        my_printf("Next : No\n");
    my_printf("Level : %d\nSize : %d*%d\n", game->flags->level,
    game->flags->map_size.col, game->flags->map_size.row);
    if (list->lenght > 1)
        sort_alpha(list);
    print_list(list);
    my_printf("Press any key to start Tetris\n");
    wait_key_pressed();
}