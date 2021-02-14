/*
** EPITECH PROJECT, 2020
** OfficialNavyRepo
** File description:
** player_one_handling_first_turn
*/

#include "../include/my.h"

extern st_global *global;

void player_one_first_attack(char *attack, size_t size, int pid_enemy)
{
    my_putstr("\nmy positions:\n");
    open_position("pos1");
    open_first_round("maps/my_navy_hit_p2.txt");
    write(1, "\n\nattack: ", 10);
    getline(&attack, &size, stdin);
    while (good_attack(attack) == 0){
        my_putstr("Wrong position\n");
        my_putstr("attack: ");
        getline(&attack, &size, stdin);
    }
    convert_to_attack(attack, pid_enemy);
    usleep(100);
}

int player_one_first_attack_is_touched(int ship_left_p2)
{
    if (hit_or_not(where_are_boat(global->sig_attack[0],
    global->sig_attack[1] - 48), "maps/my_navy2.txt") == true) {
        my_putstr(global->sig_attack);
        my_putstr(": hit");
        ship_left_p2 += 1;
    }
    else {
        my_putstr(global->sig_attack);
        my_putstr(": missed");
    }
    return (ship_left_p2);
}

int player_one_first_attack_receive(int ship_left_p1)
{
    my_putstr("\n\nwaiting for enemy’s attack...\n");
    signals_line();
    usleep(100);
    if (hit_or_not(where_are_boat(global->sig[0], global->sig[1] - 48),
    "maps/my_navy.txt") == true) {
        my_putstr(global->sig);
        my_putstr(": hit");
        ship_left_p1 += 1;
    }
    else {
        my_putstr(global->sig);
        my_putstr(": missed");
    }
    return (ship_left_p1);
}

int player_one_first_attack_display(int turn)
{
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
    turn = 1;
    return (turn);
}

void player_one_first_attack_handling(st_game *game)
{
    if (game->player == 1 && game->turn == 0) {
        if (game->player == 1 && game->turn == 0){
            player_one_first_attack(game->attack, game->size, game->pid_enemy);
            game->ship_left_p2 =
            player_one_first_attack_is_touched(game->ship_left_p2);
            if (global->attack == 1) {
                game->ship_left_p1 =
                player_one_first_attack_receive(game->ship_left_p1);
            }
            if (global->attack == 2) {
                game->turn = player_one_first_attack_display(game->turn);
            }
        }
    }
}