/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** tetris
*/

#ifndef FLAGS_H
#define FLAGS_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct option long_options[] = {
    {"level", required_argument, 0, 'L'},
    {"key-left", required_argument, 0, 'l'},
    {"key-right", required_argument, 0, 'r'},
    {"key-turn", required_argument, 0, 't'},
    {"key-drop", required_argument, 0, 'd'},
    {"key-quit", required_argument, 0, 'q'},
    {"key-pause", required_argument, 0, 'p'},
    {"map-size", required_argument, 0, 'm'},
    {"without-next", no_argument, 0, 'w'},
    {"debug", no_argument, 0, 'D'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
};

#endif