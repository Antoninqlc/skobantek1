/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-antonin.quilichini
** File description:
** modif_map.c
*/

#include "../my.h"

int get_value_player(sokoban_t *game, int x, int y)
{
    if (game->map[x][y] == 'P') {
        game->cord_p[0] = x;
        game->cord_p[1] = y;
        return 0;
    }
    return 0;
}

int get_value_hole(sokoban_t *game, int nb_o, int x, int y)
{
    if (game->map[x][y] == 'O')
        nb_o++;
    return nb_o;
}

int check_map_buff(char *str)
{
    int nb_o = 0;
    int nb_x = 0;
    int nb_p = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'X' && str[i] != 'O' && str[i] != ' '
        && str[i] != '#' && str[i] != '\n' && str[i] != 'P' && str[i] != '\0')
            return 84;
        if (str[i] == 'X')
            nb_x++;
        if (str[i] == 'P')
            nb_p++;
        if (str[i] == 'O')
            nb_o++;
    }
    if (nb_p != 1 || nb_o != nb_x || nb_o == 0)
        return 84;
    return 0;
}

int get_nb(char c)
{
    if (c == 'X')
        return 1;
    return 0;
}

int get_nb_box(sokoban_t *game)
{
    int nb_box = 0;

    for (int x = 0; game->map[x] != NULL; x++) {
        for (int y = 0; game->map[x][y] != '\0'; y++) {
            nb_box += get_nb(game->map[x][y]);
        }
    }
    return nb_box;
}
