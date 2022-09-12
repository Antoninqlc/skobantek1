/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-antman-lisa.garnier
** File description:
** antman.c
*/

int my_strlen(char const *str);

int my_strcomp(char *str, char *comp)
{
    if (my_strlen(str) != my_strlen(comp))
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != comp[i])
            return 0;
    }
    return 1;
}
