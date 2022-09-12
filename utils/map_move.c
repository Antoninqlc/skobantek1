/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-antonin.quilichini
** File description:
** map_move.c
*/

#include "../my.h"

int move_left(sokoban_t *game)
{
    if (game->map[game->cord_p[0]][game->cord_p[1] - 1] == 'X' &&
    game->map[game->cord_p[0]][game->cord_p[1] - 2] == ' ') {
        move_left_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0]][game->cord_p[1] - 1] == 'X' &&
    game->map[game->cord_p[0]][game->cord_p[1] - 2] == 'O') {
        move_left_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0]][game->cord_p[1] - 1] == ' ' ||
    game->map[game->cord_p[0]][game->cord_p[1] - 1] == 'O') {
        game->map[game->cord_p[0]][game->cord_p[1] - 1] = 'P';
        game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
        game->cord_p[1] -= 1;
        return 0;
    }
    return 0;
}

int move_right(sokoban_t *game)
{
    if (game->map[game->cord_p[0]][game->cord_p[1] + 1] == 'X' &&
    game->map[game->cord_p[0]][game->cord_p[1] + 2] == ' ') {
        move_right_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0]][game->cord_p[1] + 1] == 'X' &&
    game->map[game->cord_p[0]][game->cord_p[1] + 2] == 'O') {
        move_right_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0]][game->cord_p[1] + 1] == ' ' ||
    game->map[game->cord_p[0]][game->cord_p[1] + 1] == 'O') {
        game->map[game->cord_p[0]][game->cord_p[1] + 1] = 'P';
        game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
        game->cord_p[1] += 1;
        return 0;
    }
    return 0;
}

int move_up(sokoban_t *game)
{
    if (game->map[game->cord_p[0] - 1][game->cord_p[1]] == 'X' &&
    game->map[game->cord_p[0] - 2][game->cord_p[1]] == ' ') {
        move_up_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0] - 1][game->cord_p[1]] == 'X' &&
    game->map[game->cord_p[0] - 2][game->cord_p[1]] == 'O') {
        move_up_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0] - 1][game->cord_p[1]] == ' ' ||
    game->map[game->cord_p[0] - 1][game->cord_p[1]] == 'O') {
        game->map[game->cord_p[0] - 1][game->cord_p[1]] = 'P';
        game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
        game->cord_p[0] -= 1;
        return 0;
    }
    return 0;
}

int move_down(sokoban_t *game)
{
    if (game->map[game->cord_p[0] + 1][game->cord_p[1]] == 'X' &&
    game->map[game->cord_p[0] + 2][game->cord_p[1]] == ' ') {
        move_down_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0] + 1][game->cord_p[1]] == 'X' &&
    game->map[game->cord_p[0] + 2][game->cord_p[1]] == 'O') {
        move_down_disp(game);
        return 0;
    }
    if (game->map[game->cord_p[0] + 1][game->cord_p[1]] == ' ' ||
    game->map[game->cord_p[0] + 1][game->cord_p[1]] == 'O') {
        game->map[game->cord_p[0] + 1][game->cord_p[1]] = 'P';
        game->map[game->cord_p[0]][game->cord_p[1]] = ' ';
        game->cord_p[0] += 1;
        return 0;
    }
    return 0;
}
