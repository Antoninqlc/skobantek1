/*
** EPITECH PROJECT, 2021
** boostrap_bb
** File description:
** sokoban.c
*/

#include "my.h"

int check_map_char(char *filepath)
{
    struct stat stat_t;
    stat(filepath, &stat_t);
    int size;
    int fd;
    char *buff;

    size = stat_t.st_size;
    fd = open(filepath, O_RDONLY);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    if (check_map_buff(buff) == 84)
        return 84;
    return 0;
}

int gest_err(int ac, char **av)
{
    if (ac != 2) {
        my_putstr("Wrong usage: './my_sokoban -h' for info\n");
        return 84;
    }
    if (my_strcomp(av[1], "-h") == 1) {
        my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tFile the hole '");
        my_putstr("O' with the boxex 'X' with your player 'P' that you can m");
        my_putstr("ove with the arrow\n\tYou can reset the map with the spac");
        my_putstr("ebar or quit the game with escape\n");
        return 84;
    }
    if (open(av[1], O_RDONLY) == -1)
        return 84;
    if (check_map_char(av[1]) == 84)
        return 84;
    return 0;
}

void init_map(char *filepath, sokoban_t *game)
{
    struct stat stat_t;
    stat(filepath, &stat_t);
    int size;
    int fd;
    char *buff;
    char **map;

    size = stat_t.st_size;
    fd = open(filepath, O_RDONLY);
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    map = my_stwa(buff, '\n');
    game->map = map;
}

int get_map(char *filepath)
{
    sokoban_t game;
    init_map(filepath, &game);
    game.filepath = filepath;
    get_pos(&game);
    return sokoban(&game);
}

int main(int ac, char **av)
{
    if (gest_err(ac, av) == 84)
        return 84;
    return get_map(av[1]);
}
