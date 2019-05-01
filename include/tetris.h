/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** tetris
*/

#ifndef TETRIS_H
#define TETRIS_H

#include "../lib/my/mylib.h"
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <stdio.h>
#include <termios.h>
#include <time.h>

typedef struct t_element t_element;
struct t_element
{
    char *name;
    char ***tetri;
    int width;
    int height;
    int color_code;
    int is_error;
    t_element *next;
    t_element *prev;
};

typedef struct t_list t_list;
struct t_list
{
    t_element *first;
    t_element *last;
    int lenght;
};

typedef struct msize_t
{
    int row;
    int col;
} msize_t;

typedef struct coords_s
{
    int x;
    int y;
} coords_t;


typedef struct flags_s
{
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    msize_t map_size;
    char without_next;
    char debug;
} flags_t;

typedef struct info_s
{
    char pause;
    char lose;
    char drop_mode;
    int line_del;
    int tt_line_del;
    t_element *nx_tetri;
    t_element *cr_tetri;
    coords_t co_tetri;
    char dir_tetri;
    char **buff_game;
    time_t time_elapsed;
    time_t time_base;
    int size_max_tetri;
    int score;
    int high_score;
} info_t;

typedef struct windows_s
{
    WINDOW *game;
    WINDOW *stats;
    WINDOW *next;
} windows_t;

typedef struct game_s
{
    flags_t *flags;
    t_list *list;
    info_t *info;
    windows_t *win;
} game_t;

#define HELP_MSG "Usage:  %s [options]\nOptions:\n   --help             \
  Display this help\n   -L --level={num}     Start Tetris at level num (def: \
1)\n   -l --key-left={K}    Move the tetrimino LEFT using the K key (def: \
left arrow)\n   -r --key-right={K}   Move the tetrimino RIGHT using the K \
  key (def: right arrow)\n   -t --key-turn={K}    TURN the tetrimino clockwise\
   90d using the K key (def: top arrow)\n   -d --key-drop={K}    DROP the \
tetrimino using the K key (def: down arrow)\n   -q --key-quit={K}    \
QUIT the game using the K key (def: 'q' key)\n   -p --key-pause={K}   \
PAUSE/RESTART the game using the K key (def: space bar)\n\
   --map-size={row,col} Set the numbers of the rows and columns of the map \
(def: 20,10)\n   -w --without-next    Hide next tetrimino (def: false)\n\
   -D --debug           Debug mode (def: false)\n"

#define DEBUG_KEYS_FORMAT "Key Left : %s\nKey Right : %s\nKey Turn : %s\
\nKey Drop : %s\nKey Quit : %s\nKey Pause : %s\n"

#define TETRIS_LOGO ",--------.        ,--.         ,--.       \n\
'--.  .--',---. ,-'  '-.,--.--.`--' ,---. \n\
   |  |  | .-. :'-.  .-'|  .--',--.(  .-' \n\
   |  |  \\   --.  |  |  |  |   |  |.-'  `)\n\
   `--'   `----'  `--'  `--'   `--'`----' \n"

#define PAUSE_MSG ",------.                                \n\
|  .--. ' ,--,--.,--.,--. ,---.  ,---.  \n\
|  '--' |' ,-.  ||  ||  |(  .-' | .-. : \n\
|  | --' \\ '-'  |'  ''  '.-'  `)\\   --. \n\
`--'      `--`--' `----' `----'  `----' \n"

#define LOSE_MSG "                                                         \
,---.\n\
,--.   ,--.                 ,--.                         |   |\n\
 \\  `.'  /,---. ,--.,--.    |  | ,---.  ,---.  ,---.     |  .'\n\
  '.    /| .-. ||  ||  |    |  || .-. |(  .-' | .-. :    |  | \n\
    |  | ' '-' ''  ''  '    |  |' '-' '.-'  `)\\   --.    `--' \n\
    `--'  `---'  `----'     `--' `---' `----'  `----'    .--. \n\
                                                         '--' \n"

#define COLOR_ORANGE 10
#define NB_LINES_UP_LVL 10

/* main.c */
void end_destroys(game_t *game);
int main_next(game_t *game);
int main(int ac, char **av);

/* src/game/completed_lines.c */
int test_line_completed(char *line);
void down_line(char **buff, int y, int width);
int scoring_system(int nb, int level);
void complete_lines(game_t *game);

/* src/game/display.c */
void display_char(game_t *game, int x, int y);
void display_buff(game_t *game);
void display_tetri_next(game_t *game, int x, int y);
void display_tetri(game_t *game);
void display_next_tetri(game_t *game);

/* src/game/displays2.c */
char *print_minutes(time_t seconds);
void display_stats(game_t *game);
void display_game(game_t *game);
void refresh_all(game_t *game);

/* src/game/high_score.c */
int read_high_score(void);
void write_highscore(int score);

/* src/game/initializations_info.c */
void initialization_info_buff(game_t *game);
void clean_list(t_list *list);
void initialization_info_next(game_t *game);
int initialization_info(game_t *game);

/* src/game/initializations_game.c */
void initialization_colors(void);
void initialization_windows(game_t *game);
void initialization_game_loop(game_t *game);

/* src/game/main.c */
void term_size_error(game_t *game);
void analyse_keys(game_t *game, char *c, int width);
int analyse_event(game_t *game, char *c);
int game_loop(game_t *game);

/* src/game/menus.c */
void tetris_logo(void);
int pause_menu(game_t *game);
int end_menu(game_t *game);

/* src/game/moves.c */
int tetri_can_move_next(game_t *game, int mx, int my, int y);
int tetri_can_move(game_t *game, int mx, int my);
void tetri_dont_move(game_t *game);
void move_tetri(game_t *game);

/* src/game/rand_tetri.c */
t_element *rand_tetri(t_list *list, int choise);

/* src/game/size_max_tetri.c */
int size_max_tetri(game_t *g);

/* src/game/turns.c */
int tetri_can_turn_next(game_t *game, int y, int dir);
int tetri_can_turn(game_t *game);
void turn_tetri(game_t *game);


/* src/game/write_buff_game.c */
void write_buff_game(info_t *info, coords_t *coords);

/* src/initialization/create_rotate_tetri.c */
char **create_rotate_tetri(char **tetri, int width, int height);

/* src/initialization/debug.c */
char *transform_key(char key);
char *rtn_key(int key);
int get_key(void);
void wait_key_pressed(void);
void print_debug(t_list *list, game_t *game);

/* src/initialization/flags.c */
int verif_arg(int c);
void sc_keys(int c, flags_t *flags);
int switch_case(int c, flags_t *flags, char *exe);
int non_args(int ac, char **av, game_t *game);
int get_flags_tetris(int ac, char **av, game_t *game);

/* src/initialization/init_flags.c */
int init_flags_struct(game_t *game);

/* src/initialization/linked_lists.c */
t_element *insertion_end(t_list *list, char *str);
void print_list(t_list *list);
void destroy_ll(t_list *list);
t_list *initialisation_empty(void);
void delete_middle(t_list *list, t_element *to_delete);

/* src/initialization/my_malloc.c */
void *my_malloc(size_t size);

/* src/initialization/read_directory.c */
int open_tetriminos(game_t *g, t_list *list);
int is_good_extension(struct dirent *r_f);
int read_directory(t_list *list);

/* src/initialization/sort_alpha_functions.c */
void swap_s(t_list *list);
void rotate_rr(t_list *list);
void rotate_r(t_list *list);
void exchange_p(t_list *src, t_list *dest);
void exchange_p_following(t_list *src, t_list *dest);

/* src/initialization/sort_alpha.c */
void sort(t_list *l_a, t_list *l_b);
void end_sort(t_list *l_a, t_list *l_b);
void sort_alpha(t_list *l_a);

/* src/initialization/test_good_flag.c */
int test_good_long_flag(char *str);

/* src/initialization/verify_tetriminos.c */
void set_tetri(t_element *actual, int fd);
int tetri_is_error(game_t *g, t_list *list, t_element *actual,
char **first_line);
int verify_tetriminos(game_t *g, t_list *list, t_element *actual, int fd);


#endif