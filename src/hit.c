/*
** EPITECH PROJECT, 2020
** hit
** File description:
** hit
*/

#include "../include/my.h"

int where_hitted_letter(char c, int x)
{
    int index = 0;

    if (c == 'A')
        index = 38;
    if (c == 'B')
        index = 40;
    if (c == 'C')
        index = 42;
    if (c == 'D')
        index = 44;
    if (c == 'E')
        index = 46;
    if (c == 'F')
        index = 48;
    if (c == 'G')
        index = 50;
    if (c == 'H')
        index = 52;
    index = index + ((x - 1) * 18);
    return (index);
}

int where_are_boat(char c, int x)
{
    int index = 0;

    if (c == 'A')
        index = 38;
    if (c == 'B')
        index = 40;
    if (c == 'C')
        index = 42;
    if (c == 'D')
        index = 44;
    if (c == 'E')
        index = 46;
    if (c == 'F')
        index = 48;
    if (c == 'G')
        index = 50;
    if (c == 'H')
        index = 52;
    index = index + ((x - 1) * 18);
    return (index);
}

bool hit_or_not(int index, char *path)
{
    int fd = 0;
    char *map = malloc(sizeof(char) * 180);

    fd = open(path, O_RDWR);
    read(fd, map, 180);
    map[my_strlen(map) - 1] = '\0';
    if (map[index] == '2' || map[index] == '3' || map[index] == '4' \
    || map[index] == '5') {
        close(fd);
        return (true);
    }
    else {
        close(fd);
        return (false);
    }
    return (false);
}

bool check_boats(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (i == 36 || i == 53 || i == 70 || i == 87 || i == 104 || i == 121 \
        || i == 138 || i == 155)
            i++;
        if (map[i] == '2' || map[i] == '3' || map[i] == '4' || map[i] == '5')
            return (false);
        else
            return (true);
    }
}