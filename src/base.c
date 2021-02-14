/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** base
*/

#include "../include/my.h"

int where_in_base(char nb, char *base)
{
    int i = 0;

    while (base[i] != '\0') {
        if (base[i] == nb)
            return (i);
        i++;
    }
    return (-1);
}

int is_in_base(char c, char *base)
{
    int i = 0;

    while (base[i] != '\0') {
        if (base[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void base_check(char *str, char *base)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_in_base(str[i], base) == 0) {
            my_putstr("syntax error");
            exit(84);
        }
        i++;
    }
}

int base_size(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}