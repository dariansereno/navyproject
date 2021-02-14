/*
** EPITECH PROJECT, 2020
** boat positions
** File description:
** boat_positions
*/

#include "../include/my.h"

void open_position_p2(char *path)
{
    int fd = 0;
    char *map = malloc(sizeof(char) * 50);
    char **map_double = NULL;

    fd = open(path, O_RDONLY);
    read(fd, map, 50);
    map_double = my_str_to_word_array(map, "\n");
    check_file(map_double);
    recover_position_p2(map_double);
    close(fd);
}

void recover_position_p2(char **map)
{
    char *map_single = NULL;

    for (int i = 0; i < 2; i++) {
        if (map[0][2] == map[0][5])
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[0][2], map[0][3] - 48 + i), map[0][0]);
        else
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[0][2] + i, map[0][3] - 48), map[0][0]);
    }
    for (int i = 0; i < 3; i++) {
        if (map[1][2] == map[1][5])
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[1][2], map[1][3] - 48 + i), map[1][0]);
        else
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[1][2] + i, map[1][3] - 48), map[1][0]);
    }
    map_single = recover_position2_p2(map);
    my_putstr(map_single);
}

char *recover_position2_p2(char **map)
{
    char *map_single = NULL;

    for (int i = 0; i < 4; i++) {
        if (map[2][2] == map[2][5])
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[2][2], map[2][3] - 48 + i), map[2][0]);
        else
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[2][2] + i, map[2][3] - 48), map[2][0]);
    }
    for (int i = 0; i < 5; i++) {
        if (map[3][2] == map[3][5])
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[3][2], map[3][3] - 48 + i), map[3][0]);
        else
            map_single = openfile_show("maps/my_navy2.txt", \
            where_are_boat(map[3][2] + i, map[3][3] - 48), map[3][0]);
    }
    return (map_single);
}