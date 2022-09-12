/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-antonin.quilichini
** File description:
** map_move_disp.c
*/

#include "../my.h"

void move_left_disp(sokoban_t *game)
{
    game->map[game->cord_p[0]][game->cord_p[1] - 1] = 'P';
    game->map[game->cord_p[0]][game->cord_p[1] - 2] = 'X';
    game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
    game->cord_p[1] -= 1;
}

void move_right_disp(sokoban_t *game)
{
    game->map[game->cord_p[0]][game->cord_p[1] + 1] = 'P';
    game->map[game->cord_p[0]][game->cord_p[1] + 2] = 'X';
    game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
    game->cord_p[1] += 1;
}

void move_up_disp(sokoban_t *game)
{
    game->map[game->cord_p[0] - 1][game->cord_p[1]] = 'P';
    game->map[game->cord_p[0] - 2][game->cord_p[1]] = 'X';
    game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
    game->cord_p[0] -= 1;
}

void move_down_disp(sokoban_t *game)
{
    game->map[game->cord_p[0] + 1][game->cord_p[1]] = 'P';
    game->map[game->cord_p[0] + 2][game->cord_p[1]] = 'X';
    game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
    game->cord_p[0] += 1;
}
