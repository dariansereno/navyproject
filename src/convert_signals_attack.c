/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** convert_signals_attack
*/

#include "../include/my.h"

int convert_line_attack(char c, int line)
{
    switch (c) {
    case 65:
        line = 1;
        break;
    case 66:
        line = 2;
        break;
    case 67:
        line = 3;
        break;
    case 68:
        line = 4;
        break;
    default:
        line = convert_line_attack2(c, line);
        break;
    }
    return (line);
}

int convert_line_attack2(char c, int line)
{
    switch(c) {
    case 69:
        line = 5;
        break;
    case 70:
        line = 6;
        break;
    case 71:
        line = 7;
        break;
    case 72:
        line = 8;
        break;
    default:
        line = -1;
        break;
    }
    return (line);
}

int convert_column_attack(char c, int column)
{
    switch (c) {
    case 49:
        column = 1;
        break;
    case 50:
        column = 2;
        break;
    case 51:
        column = 3;
        break;
    case 52:
        column = 4;
        break;
    default:
        column = convert_column_attack2(c, column);
        break;
    }
    return (column);
}

int convert_column_attack2(char c, int column)
{
    switch(c) {
    case 53:
        column = 5;
        break;
    case 54:
        column = 6;
        break;
    case 55:
        column = 7;
        break;
    case 56:
        column = 8;
        break;
    default:
        column = -1;
        break;
    }
    return (column);
}