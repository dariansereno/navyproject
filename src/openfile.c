/*
** EPITECH PROJECT, 2020
** openfile
** File description:
** opener
*/

#include "../include/my.h"

void open_first_round(char *path)
{
    int fd = 0;
    char *map = malloc(sizeof(char) * 180);

    fd = open(path, O_RDWR);
    read(fd, map, 180);
    write(1, "\n\nenemy's positions:\n", 21);
    map[my_strlen(map) - 1] = '\0';
    my_putstr(map);
    close(fd);
}

void openfile_hit(char *path, bool hit, int index)
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
    write(1, "\n\nenemy's positions:\n", 21);
    map_single[my_strlen(map_single) - 1] = '\0';
    my_putstr(map_single);
    close(fd[1]);
}

char *changed_map_hit(char *map, bool hit, int index)
{
    if (hit == true)
        map[index] = 'x';
    else
        map[index] = 'o';
    return (map);
}

char *openfile_show(char *path, int index, char length)
{
    int fd[2];
    char *map = malloc(sizeof(char) * 180);
    char *map_single = NULL;

    fd[0] = open(path, O_RDWR);
    read(fd[0], map, 180);
    map_single = changed_map_show(map, index, length);
    lseek(fd[0], 0, SEEK_SET);
    write(fd[0], map_single, my_strlen(map));
    close(fd[0]);
    fd[1] = open(path, O_RDONLY);
    read(fd[1], map_single, 180);
    close(fd[1]);
    map_single[my_strlen(map_single) - 1] = '\0';
    return (map_single);
}

char *changed_map_show(char *map, int index, char length)
{
    map[index] = length;
    return (map);
}