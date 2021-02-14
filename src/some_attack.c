/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** game_handling
*/

#include "../include/my.h"

extern st_global *global;

char return_letter(int line)
{
    switch (line) {
    case 1:
        return ('A');
    case 2:
        return ('B');
    case 3:
        return ('C');
    case 4:
        return ('D');
    case 5:
        return ('E');
    case 6:
        return ('F');
    case 7:
        return ('G');
    case 8:
        return ('H');
    default:
        return ('Z');
    }
}

void line_attack(char *line_str, int pid_enemy)
{
    int i = 0;

    while (line_str[i] != '\0') {
        if (line_str[i] == '0')
            kill(pid_enemy, SIGUSR1);
        else if (line_str[i] == '1')
            kill(pid_enemy, SIGUSR2);
        usleep(100);
        i++;
    }
}

void column_attack(char *column_str, int pid_enemy)
{
    int i = 0;
    while (column_str[i] != '\0') {
        if (column_str[i] == '0')
            kill(pid_enemy, SIGUSR1);
        else if (column_str[i] == '1')
            kill(pid_enemy, SIGUSR2);
        usleep(100);
        i++;
    }
}