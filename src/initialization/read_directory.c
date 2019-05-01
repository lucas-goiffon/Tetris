/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** read_directory
*/

#include "../../include/tetris.h"

int open_tetriminos(game_t *g, t_list *list)
{
    t_element *actual = list->first;
    int fd;
    char *path;

    while (actual != NULL) {
        path = my_strcat_two("tetriminos/", actual->name);
        fd = open(path, O_RDONLY);
        if (fd < 0)
            return (84);
        verify_tetriminos(g, list, actual, fd);
        if (close(fd) < 0)
            return (84);
        free(path);
        actual = actual->next;
    }
    return (0);
}

int is_good_extension(struct dirent *r_f)
{
    char *name = r_f->d_name;

    if (name[0] == '.' && (name[1] =='\0' || name[1] == '.'))
        return (84);
    for (int i = 0; name[i] != '\0'; i = i + 1) {
        if (name[i] == '.') {
            name = &name[i];
            i = 0;
        }
    } if (my_strcmp(name, ".tetrimino") != 0)
        return (84);
    return (0);
}

int read_directory(t_list *list)
{
    DIR *directory = NULL;
    struct dirent *readed_file = NULL;

    directory = opendir("./tetriminos");
    if (directory == NULL) {
        my_putstr_error("No tetriminos directory\n");
        return (84);
    }
    while ((readed_file = readdir(directory)) != NULL) {
        if (readed_file->d_type == 8 && is_good_extension(readed_file) == 0)
            insertion_end(list, readed_file->d_name);
    }
    if (closedir(directory) == -1)
        return (84);
    return (0);
}