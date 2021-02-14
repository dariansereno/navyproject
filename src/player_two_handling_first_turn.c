/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** player_two_handling_first_turn
*/

#include "../include/my.h"

extern st_global *global;

void player_two_first_attack_receive(st_game *game)
{
    my_putstr("\nmy positions:\n");
    open_position_p2("pos2");
    open_first_round("maps/my_navy_hit_p1.txt");
    my_putstr("\n\nwaiting for enemy’s attack...\n");
    signals_line();
    usleep(100);
    if (hit_or_not(where_are_boat(global->sig[0], global->sig[1] - 48),
    "maps/my_navy2.txt") == true) {
        my_putstr(global->sig);
        my_putstr(": hit");
        game->ship_left_p2 += 1;
    }
    else {
        my_putstr(global->sig);
        my_putstr(": missed");
    }
}

void player_two_first_attack(st_game *game)
{
    usleep(100);
    write(1, "\n\nattack: ", 10);
    getline(&game->attack, &game->size, stdin);
    convert_to_attack(game->attack, game->pid_enemy);
    if (hit_or_not(where_are_boat(global->sig_attack[0],
    global->sig_attack[1] - 48), "maps/my_navy.txt") == true) {
        my_putstr(global->sig_attack);
        my_putstr(": hit");
        game->ship_left_p1 += 1;
    }
    else {
        my_putstr(global->sig_attack);
        my_putstr(": missed");
    }
}

int player_two_first_attack_display(int turn)
{
    usleep(100);
    openfile2_hit("maps/my_navy2.txt",
    hit_or_not(where_are_boat(global->sig[0], global->sig[1] - 48),
    "maps/my_navy2.txt"),
    where_hitted_letter(global->sig[0], global->sig[1] - 48));
    openfile_hit("maps/my_navy_hit_p2.txt",
    hit_or_not(where_are_boat(global->sig_attack[0],
    global->sig_attack[1] - 48), "maps/my_navy.txt"),
    where_hitted_letter(global->sig_attack[0], global->sig_attack[1] - 48));
    global->attack = 0;
    turn = 1;
    return (turn);
}

void player_two_first_attack_handling(st_game *game)
{
    if (game->player == 2 && game->turn == 0){
        player_two_first_attack_receive(game);
        if (global->attack == 1) {
            player_two_first_attack(game);
        }
        if (global->attack == 2) {
            game->turn = player_two_first_attack_display(game->turn);
        }
        write(1, "\n", 1);
    }
}