/*
** EPITECH PROJECT, 2020
** boat positions
** File description:
** boat_positions
*/

#include "../include/my.h"

void check_file(char **map)
{
    if (map[0][0] != '2' || map[1][0] != '3' || map[2][0] != '4' || \
    map[3][0] != '5')
        exit(84);
    if (map[0][1] != ':' || map[1][1] != ':' || map[2][1] != ':' || \
    map[3][1] != ':')
        exit(84);
    if (map[0][4] != ':' || map[1][4] != ':' || map[2][4] != ':' || \
    map[3][4] != ':')
        exit(84);
    if ((map[0][2] < 65 || map[0][2] > 72) || (map[1][2] < 65 || \
    map[1][2] > 72) || (map[2][2] < 65 || map[2][2] > 72) || \
    (map[3][2] < 65 || map[3][2] > 72))
        exit(84);
    if ((map[0][5] < 65 || map[0][5] > 72) || (map[1][5] < 65 || \
    map[1][5] > 72) || (map[2][5] < 65 || map[2][5] > 72) || \
    (map[3][5] < 65 || map[3][5] > 72))
        exit(84);
    check_file2(map);
}

void check_file2(char **map)
{
    if ((map[0][3] < 49 || map[0][3] > 56) || (map[1][3] < 49 || \
    map[1][3] > 56) || (map[2][3] < 49 || map[2][3] > 56) || \
    (map[3][3] < 49 || map[3][3] > 56))
        exit(84);
    if ((map[0][6] < 49 || map[0][6] > 56) || (map[1][6] < 49 || \
    map[1][6] > 56) || (map[2][6] < 49 || map[2][6] > 56) || \
    (map[3][6] < 49 || map[3][6] > 56))
        exit(84);
}

void open_position(char *path)
{
    int fd = 0;
    char *map = malloc(sizeof(char) * 50);
    char **map_double = NULL;

    fd = open(path, O_RDONLY);
    read(fd, map, 50);
    map_double = my_str_to_word_array(map, "\n");
    check_file(map_double);
    recover_position(map_double);
    close(fd);
}

void recover_position(char **map)
{
    char *map_single = NULL;

    for (int i = 0; i < 2; i++) {
        if (map[0][2] == map[0][5])
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[0][2], map[0][3] - 48 + i), map[0][0]);
        else
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[0][2] + i, map[0][3] - 48), map[0][0]);
    }
    for (int i = 0; i < 3; i++) {
        if (map[1][2] == map[1][5])
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[1][2], map[1][3] - 48 + i), map[1][0]);
        else
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[1][2] + i, map[1][3] - 48), map[1][0]);
    }
    map_single = recover_position2(map);
    my_putstr(map_single);
}

char *recover_position2(char **map)
{
    char *map_single = NULL;

    for (int i = 0; i < 4; i++) {
        if (map[2][2] == map[2][5])
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[2][2], map[2][3] - 48 + i), map[2][0]);
        else
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[2][2] + i, map[2][3] - 48), map[2][0]);
    }
    for (int i = 0; i < 5; i++) {
        if (map[3][2] == map[3][5])
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[3][2], map[3][3] - 48 + i), map[3][0]);
        else
            map_single = openfile_show("maps/my_navy.txt", \
            where_are_boat(map[3][2] + i, map[3][3] - 48), map[3][0]);
    }
    return (map_single);
}