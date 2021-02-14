/*
** EPITECH PROJECT, 2020
** openfile
** File description:
** opener
*/

#include "../include/my.h"

void openfile2_hit(char *path, bool hit, int index)
{
    int fd[2];
    char *map = malloc(sizeof(char) * 180);
    char *map_single = NULL;

    fd[0] = open(path, O_RDWR);
    read(fd[0], map, 180);
    map_single = changed_map_hit(map, hit, index);
    lseek(fd[0], 0, SEEK_SET);
    write(fd[0], map_single, my_strlen(map));
    close(fd[0]);
    fd[1] = open(path, O_RDONLY);
    read(fd[1], map_single, 180);
    write(1, "\n\nmy positions:\n", 16);
    map_single[my_strlen(map_single) - 1] = '\0';
    my_putstr(map_single);
    close(fd[1]);
}