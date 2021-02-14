/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main function
*/

#include "../include/my.h"

st_global *global;

void initalize_global(void)
{
    global = malloc(sizeof(st_global));
    global->sig = malloc(sizeof(char) * 3);
    global->sig[2] = '\0';
    global->binary = malloc(sizeof(char) * 9);
    global->binary[8] = '\0';
    global->i = 0;
    global->attack = 0;
    global->stop = 0;
    global->connected = 0;
    global->sig_attack = malloc(sizeof(char) * 3);
}

void reinitalize_global(void)
{
    global = malloc(sizeof(st_global));
    global->sig = "A0";
    global->sig[2] = '\0';
    global->binary = "00000000";
    global->binary[8] = '\0';
    global->i = 0;
}

int main(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 0)
        write(1, "USAGE\n\t./navy [first_player_pid] navy_positions\n\
DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.\n\t\
pid of the first player.navy_positions: file representing \
the positions of the ships.", 195);
    else {
        initalize_global();
        reset_maps();
        if (my_strcmp(argv[1], "pos1") == 0)
            connection_p1("pos1");
        if (argc == 3) {
            if (my_strcmp(argv[2], "pos2") == 0)
                connection_p2(argv[1], "pos2");
        }
        else {
            write(2, "Please enter valid arguments", 28);
            exit(84);
        }
    }
}
