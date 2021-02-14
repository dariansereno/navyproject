/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** base2
*/

#include "../include/my.h"

int convert_in_decimal(char *nb, char *base)
{
    int i = 0;
    int converted = 0;
    int base_length = my_strlen(base);
    base_check(nb, base);

    while (nb[i] != '\0') {
        converted = converted * base_length;
        converted = converted + where_in_base(nb[i], base);
        i++;
    }
    return (converted);
}

int final_len_converted(int nb, int base_length)
{
    int i = 0;

    while (nb != 0) {
        nb /= base_length;
        i++;
    }
    return (i);
}

char *fill_with_zero(char *converted, int i, int final_size)
{
    if (final_size == 1) {
        converted[i++] = '0';
        converted[i++] = '0';
        converted[i++] = '0';
    }
    if (final_size == 2) {
        converted[i++] = '0';
        converted[i++] = '0';
    }
    if (final_size == 3)
        converted[i++] = '0';
    converted[i++] = '\0';
    return (converted);
}

char *convert_to_base(int nb, char *base)
{
    int i = 0;
    int neg = 0;
    int base_length = my_strlen(base);
    int final_size = final_len_converted(nb, base_length);
    char *converted = malloc(sizeof(char) * 5);

    if (nb <= 0) {
        neg = 1;
        nb *= -1;
    }
    while (nb != 0) {
        converted[i] = base[nb % base_length];
        nb /= base_length;
        i++;
    }
    if (neg == 1)
        converted[i++] = '-';
    converted = fill_with_zero(converted, i, final_size);
    my_revstr(converted);
    return (converted);
}
