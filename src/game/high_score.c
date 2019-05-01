/*
** EPITECH PROJECT, 2019
** high_score.c
** File description:
** high_score
*/

#include "../../include/tetris.h"

int read_high_score(void)
{
    int file = open("./highscore", O_CREAT|O_RDONLY,
    S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    int score = 0;

    read(file, &score, sizeof(int));
    return (score);
}

void write_highscore(int score)
{
    int file = open("./highscore", O_CREAT|O_WRONLY,
    S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

    write(file, &score, sizeof(int));
}