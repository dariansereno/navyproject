/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** game
*/

#include "../include/my.h"
#include "../include/signal.h"

extern st_global *global;

int convert_to_attack(char *str, int pid_enemy)
{
    int line = 0;
    int column = 0;
    char *line_str = 0;
    char *column_str = 0;

    line = convert_line_attack(str[0], line);
    column = convert_column_attack(str[1], column);
    if (line == -1)
        return (0);
    if (column == -1)
        return (0);
    line_str = convert_to_base(line, "01");
    line_attack(line_str, pid_enemy);
    column_str = convert_to_base(column, "01");
    column_attack(column_str, pid_enemy);
    global->sig_attack[0] = return_letter(line);
    global->sig_attack[1] = column + 48;
    global->sig_attack[2] = '\0';
    global->attack += 1;
    return (0);
}

int good_attack(char *attack)
{
    if (!((attack[0] >= 'A' && attack[0] <= 'H') &&
    (attack[1] >= '1' && attack[1] <= '8')))
        return (0);
    return (1);
}

void win_condition(st_game game)
{
    if (game.ship_left_p1 == 14) {
        if (game.player == 1)
            my_putstr("\nEnemy won\n");
        else
            my_putstr("\nI won");
    }
    if (game.ship_left_p2 == 14) {
        if (game.player == 1)
            my_putstr("\nI won\n");
        else
            my_putstr("Enemy won");
    }
}

void game_start(int pid_enemy, int player)
{
    st_game game;
    game.pid_enemy = pid_enemy;
    game.player = player;
    game.attack = malloc(sizeof(char) * 2);
    game.size = 2;
    game.ship_left_p1 = 0;
    game.ship_left_p2 = 0;
    game.turn = 0;

    player_one_first_attack_handling(&game);
    player_two_first_attack_handling(&game);

    while (game.ship_left_p1 < 14 && game.ship_left_p2 < 14) {
        player_one_handling(&game);
        player_two_handling(&game);
        win_condition(game);
    }
    pause();
}