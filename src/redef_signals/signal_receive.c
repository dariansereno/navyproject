/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** signal_receive
*/

#include "../../include/my.h"

extern st_global *global;

char letter_convert(int nb)
{
    switch (nb) {
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

char number_convert(int nb)
{
    switch (nb) {
    case 1:
        return ('1');
    case 2:
        return ('2');
    case 3:
        return ('3');
    case 4:
        return ('4');
    case 5:
        return ('5');
    case 6:
        return ('6');
    case 7:
        return ('7');
    case 8:
        return ('8');
    default:
        return ('Z');
    }
}

int receive_convert(char *signal)
{
    char **letter_number = split_my_binary(signal);
    int letter_before_char = convert_in_decimal(letter_number[0], "01");
    int number_before_char = convert_in_decimal(letter_number[1], "01");
    char letter = letter_convert(letter_before_char);
    char number = number_convert(number_before_char);

    global->sig[0] = letter;
    global->sig[1] = number;
    global->attack += 1;
    return (0);
}

char **split_my_binary(char *signal)
{
    char **letter_number = malloc(sizeof(char *) * 2);

    letter_number[0] = malloc(sizeof(char) * 5);
    letter_number[1] = malloc(sizeof(char) * 5);
    letter_number[0][0] = signal[0];
    letter_number[0][1] = signal[1];
    letter_number[0][2] = signal[2];
    letter_number[0][3] = signal[3];
    letter_number[0][4] = '\0';
    letter_number[1][0] = signal[4];
    letter_number[1][1] = signal[5];
    letter_number[1][2] = signal[6];
    letter_number[1][3] = signal[7];
    letter_number[1][4] = '\0';
    return (letter_number);
}

void global_binary_change(void)
{
    global->binary[global->i++] = '\0';
    global->i = 0;
    receive_convert(global->binary);
}