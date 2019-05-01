/*
** EPITECH PROJECT, 2019
** test_good_flag.c
** File description:
** test_good_flag
*/

#include "../../include/tetris.h"

int test_good_long_flag(char *str)
{
    if (!my_strncmp(str, "--level", 6) && str[7] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--key-left", 9) && str[10] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--key-right", 10) && str[11] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--key-turn", 9) && str[10] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--key-drop", 9) && str[10] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--key-quit", 9) && str[10] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--key-pause", 10) && str[11] == 0)
        return (my_printf("Error argument\n"));
    if (!my_strncmp(str, "--map-size", 9) && str[10] == 0)
        return (my_printf("Error argument\n"));
    return (0);
}