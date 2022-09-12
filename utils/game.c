/*
** EPITECH PROJECT, 2021
** boostrap_bb
** File description:
** game.c
*/

#include "../my.h"

int get_move(sokoban_t *game)
{
    int input = getch();

    if (input == KEY_LEFT)
        move_left(game);
    if (input == KEY_RIGHT)
        move_right(game);
    if (input == KEY_UP)
        move_up(game);
    if (input == KEY_DOWN)
        move_down(game);
    if (input == ' ') {
        init_map(game->filepath, game);
        get_pos(game);
    }
    if (input == 27)
        return 0;
    return check_hole(game);
}

int *print_map(int *cord)
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    wbkgd(stdscr, COLOR_PAIR(1));
    curs_set(0);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, cord[0], cord[1]);
    clear();
    return cord;
}

int max_len(sokoban_t *game)
{
    int max_len = 0;

    for (int i = 0; game->map[i] != NULL; i++) {
        if (my_strlen(game->map[i]) > max_len)
            max_len = my_strlen(game->map[i]);
    }
    return max_len;
}

int print_map_end(sokoban_t *game)
{
    int *cord = malloc(sizeof(int) * 2);

    cord = print_map(cord);
    for (int i = 0; game->map[i] != NULL; i++) {
        attron(COLOR_PAIR(2));
        mvprintw((cord[0] / 3) + i, (cord[1] / 2) -
        (max_len(game) / 2) , game->map[i]);
        attroff(COLOR_PAIR(2));
    }
    refresh();
    return 0;
}

int sokoban(sokoban_t *game)
{
    int *cord = malloc(sizeof(int) * 2);
    int ret;

    initscr();
    while (1) {
        cord = print_map(cord);
        for (int i = 0; game->map[i] != NULL; i++) {
            attron(COLOR_PAIR(2));
            mvprintw((cord[0] / 3) + i, (cord[1] / 2) -
            (max_len(game) / 2) , game->map[i]);
            attroff(COLOR_PAIR(2));
        }
        refresh();
        ret = get_move(game);
        if (ret != 3) {
            print_map_end(game);
            endwin();
            return ret;
        }
    }
}
