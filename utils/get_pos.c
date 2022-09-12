/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-antonin.quilichini
** File description:
** get_pos.c
*/

#include "../my.h"

int get_pos_player(sokoban_t *game)
{
    game->cord_p = malloc(sizeof(int) * 2);
    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            get_value_player(game, x, y);
        }
    }
    return 0;
}

int get_nb_hole(sokoban_t *game, int x, int y, int nb_o)
{
    if (game->map[x][y] == 'O') {
        game->cord_h[nb_o] = malloc(sizeof(int) * 2);
        game->cord_h[nb_o][0] = x;
        game->cord_h[nb_o][1] = y;
        nb_o++;
    }
    return nb_o;
}

void get_pos_hole(sokoban_t *game)
{
    int nb_o = 0;

    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            nb_o = get_value_hole(game, nb_o, x, y);
        }
    }
    game->cord_h = malloc(sizeof(int *) * (nb_o + 1));
    game->cord_h[nb_o] = NULL;
    for (int x = 0, nb_o = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            nb_o = get_nb_hole(game, x, y, nb_o);
        }
    }
}

int check_hole_map(sokoban_t *game, int *pos, int nb_stuck_box, int nb_box)
{
    if (game->map[pos[0]][pos[1]] == 'X') {
        nb_stuck_box += check_lose(game, pos[0], pos[1]);
        nb_box++;
    }
    return nb_stuck_box;
}

void get_pos(sokoban_t *game)
{
    get_pos_player(game);
    get_pos_hole(game);
}
