/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-antonin.quilichini
** File description:
** check_hole.c
*/

#include "../my.h"

int check_lose(sokoban_t *game, int x, int y)
{
    if ((game->map[x - 1][y] == '#' || game->map[x - 1][y] == 'X')
    && (game->map[x][y - 1] == '#' || game->map[x][y - 1] == 'X'))
        return 1;
    if ((game->map[x + 1][y] == '#' || game->map[x + 1][y] == 'X')
    && (game->map[x][y + 1] == '#' || game->map[x][y + 1] == 'X'))
        return 1;
    if ((game->map[x + 1][y] == '#' || game->map[x + 1][y] == 'X')
    && (game->map[x][y - 1] == '#' || game->map[x][y - 1] == 'X'))
        return 1;
    if ((game->map[x - 1][y] == '#' || game->map[x - 1][y] == 'X')
    && (game->map[x][y + 1] == '#' || game->map[x][y + 1] == 'X'))
        return 1;
    return 0;
}

int check_victory(sokoban_t *game)
{
    int box_in = 0;
    int i = 0;

    for (i = 0; game->cord_h[i] != NULL; i++) {
        if (game->map[game->cord_h[i][0]][game->cord_h[i][1]] == 'X') {
            box_in++;
        }
    }
    if (box_in == i)
        return 0;
    return 3;
}

int nb_box_in(sokoban_t *game)
{
    int box_in = 0;

    for (int i = 0; game->cord_h[i] != NULL; i++) {
        if (game->map[game->cord_h[i][0]][game->cord_h[i][1]] == 'X') {
            box_in++;
        }
    }
    return box_in;
}

int check_hole(sokoban_t *game)
{
    int nb_stuck_box = 0;
    int nb_box = 0;
    int *pos = malloc(sizeof(int) * 2);

    nb_box = get_nb_box(game);
    for (int i = 0; game->cord_h[i] != NULL; i++) {
        if (game->map[game->cord_h[i][0]][game->cord_h[i][1]] == ' ') {
            game->map[game->cord_h[i][0]][game->cord_h[i][1]] = 'O';
        }
    }
    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            pos[0] = x;
            pos[1] = y;
            nb_stuck_box = check_hole_map(game, pos, nb_stuck_box, nb_box);
        }
    }
    if (nb_stuck_box == nb_box)
        return 1;
    return check_victory(game);
}
