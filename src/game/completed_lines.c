/*
** EPITECH PROJECT, 2019
** completed_line.c
** File description:
** completed_lines
*/

#include "../../include/tetris.h"

int test_line_completed(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == ' ')
            return (0);
    }
    return (1);
}

void down_line(char **buff, int y, int width)
{
    for (int i = y; i > 0; i--)
        buff[i] = my_strcpy(buff[i], buff[i - 1]);
    for (int i = 0; i < width; i++)
        buff[0][i] = ' ';
}

int scoring_system(int nb, int level)
{
    if (nb == 1)
        return (40 * (level + 1));
    if (nb == 2)
        return (100 * (level + 1));
    if (nb == 3)
        return (300 * (level + 1));
    if (nb == 4)
        return (1200 * (level + 1));
    return (0);
}

void complete_lines(game_t *game)
{
    int line_del_now = 0;

    for (int i = 0; game->info->buff_game[i]; i++) {
        if (test_line_completed(game->info->buff_game[i])) {
            down_line(game->info->buff_game, i, game->flags->map_size.col);
            game->info->line_del += 1;
            game->info->tt_line_del += 1;
            line_del_now++;
        }
    }
    if (game->info->line_del >= NB_LINES_UP_LVL) {
        game->flags->level += 1;
        game->info->line_del -= NB_LINES_UP_LVL;
    }
    game->info->score += scoring_system(line_del_now, game->flags->level);
}