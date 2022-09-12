/*
** EPITECH PROJECT, 2021
** boostrap_bb
** File description:
** my.h
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/stat.h>

#pragma once

typedef struct sokoban_st {
    char *filepath;
    int *cord_p;
    int **cord_h;
    char **map;
} sokoban_t;

int my_strlen(char const *str);
int sokoban(sokoban_t *map);
void get_pos(sokoban_t *game);
int move_left(sokoban_t *map);
void move_left_disp(sokoban_t *game);
int move_right(sokoban_t *game);
void move_right_disp(sokoban_t *game);
int move_up(sokoban_t *game);
void move_up_disp(sokoban_t *game);
int move_down(sokoban_t *game);
void move_down_disp(sokoban_t *game);
int check_hole(sokoban_t *game);
void init_map(char *filepath, sokoban_t *game);
int my_strcomp(char *str, char *comp);
void my_putstr(char const *str);
char **my_stwa(char *str, char sep);
int check_hole_map(sokoban_t *game, int *pos, int nb_stuck_box, int nb_box);
int get_value_player(sokoban_t *game, int x, int y);
int check_lose(sokoban_t *game, int x, int y);
int get_value_hole(sokoban_t *game, int nb_o, int x, int y);
int check_map_buff(char *str);
int get_nb_box(sokoban_t *game);
