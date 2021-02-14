/*
** EPITECH PROJECT, 2020
** reset maps
** File description:
** reset_maps
*/

#include "../include/my.h"

void reset_maps(void)
{
    reset_openfile("maps/my_navy.txt");
    reset_openfile("maps/my_navy2.txt");
    reset_openfile("maps/my_navy_hit_p1.txt");
    reset_openfile("maps/my_navy_hit_p2.txt");
}

void reset_openfile(char *path)
{
    int fd[2];
    char *map = malloc(sizeof(char) * 180);
    char *map_reset = NULL;

    fd[0] = open(path, O_RDWR);
    read(fd[0], map, 180);
    map_reset = reset_change();
    lseek(fd[0], 0, SEEK_SET);
    write(fd[0], map_reset, my_strlen(map_reset));
    close(fd[0]);
    fd[1] = open(path, O_RDONLY);
    read(fd[1], map_reset, 180);
    map_reset[my_strlen(map_reset) - 1] = '\0';
    close(fd[1]);
}

char *reset_change(void)
{
    int fd = 0;
    char *map_reset = malloc(sizeof(char) * 180);
    char *map = malloc(sizeof(char) * 180);

    fd = open("maps/backup.txt", O_RDWR);
    read(fd, map, 180);
    map[my_strlen(map) - 1] = '\0';
    for (int i = 0; map[i] != '\0'; i++)
        map_reset[i] = map[i];
    close(fd);
    return (map_reset);
}
