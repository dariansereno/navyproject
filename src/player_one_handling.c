/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** player_one_handling
*/

#include "../include/my.h"

extern st_global *global;

void player_one_attack(st_game *game)
{
    write(1, "\n\nattack: ", 10);
    getline(&game->attack, &game->size, stdin);
    convert_to_attack(game->attack, game->pid_enemy);
    usleep(100);
    if (hit_or_not(where_are_boat(global->sig_attack[0],
    global->sig_attack[1] - 48), "maps/my_navy2.txt") == true) {
        my_putstr(global->sig_attack);
        my_putstr(": hit");
        game->ship_left_p2 += 1;
    }
    else {
        my_putstr(global->sig_attack);
        my_putstr(": missed");
    }
}

void player_one_receive(st_game *game)
{
    if (global->attack == 1) {
        usleep(100);
        my_putstr("\n\nwaiting for enemy’s attack...\n");
        signals_line();
        if (hit_or_not(where_are_boat(global->sig[0], global->sig[1] - 48),
        "maps/my_navy.txt") == true) {
            my_putstr(global->sig);
            my_putstr(": hit");
            game->ship_left_p1 += 1;
        }
        else {
            my_putstr(global->sig);
            my_putstr(": missed");
        }
    }
}

void player_one_display(void)
{
    if (global->attack == 2) {
        usleep(100);
        openfile2_hit("maps/my_navy.txt",
        hit_or_not(where_are_boat(global->sig[0], global->sig[1] - 48),
        "maps/my_navy.txt"), where_hitted_letter(global->sig[0],
        global->sig[1] - 48));
        openfile_hit("maps/my_navy_hit_p1.txt",
        hit_or_not(where_are_boat(global->sig_attack[0],
        global->sig_attack[1] - 48), "maps/my_navy2.txt"),
        where_hitted_letter(global->sig_attack[0], global->sig_attack[1] - 48));
        global->attack = 0;
    }
}

void player_one_handling(st_game *game)
{
    if (game->player == 1) {
        player_one_attack(game);
        player_one_receive(game);
        player_one_display();
    }
}