/*
** EPITECH PROJECT, 2020
** Day03
** File description:
** my_isneg.c
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n >= 0)
        write(1, "P", 2);
    else
        write(1, "N", 2);
    return (0);
}
