/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-antonin.quilichini
** File description:
** my_putstr.c
*/

#include "../my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
