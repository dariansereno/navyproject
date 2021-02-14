/*
** EPITECH PROJECT, 2020
** signals navy
** File description:
** signals
*/

#include "../../include/my.h"

extern st_global *global;

void signal_start(int sig, siginfo_t *sig_info, void *data)
{
    (void)sig;
    (void)data;
    write(1, "\nenemy connected\n", 17);
    global->stop = 1;
    global->pid_enemy = sig_info->si_pid;
    global->connected = 1;
    return ;
}

void signal_zero(int sig)
{
    (void)sig;
    global->binary[global->i++] = '0';
    return ;
}

void signal_one(int sig)
{
    (void)sig;
    global->binary[global->i++] = '1';
    return ;
}

int signal_connect(void)
{
    struct sigaction start_game;

    start_game.sa_sigaction = &signal_start;
    start_game.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR2, &start_game, NULL) == -1)
        my_putstr("ERROR");
    while (global->stop == 1)
        usleep(100);
    return (0);
}

void signals_line(void)
{
    struct sigaction action;
    struct sigaction action2;
    int signaled = 0;

    action.sa_handler = &signal_zero;
    action.sa_flags = SA_SIGINFO;
    action2.sa_handler = &signal_one;
    action2.sa_flags = SA_SIGINFO;
    while (signaled != 8) {
        if (sigaction(SIGUSR1, &action, NULL) == 0) {
            signaled++;
            usleep(500);
        }
        if (sigaction(SIGUSR2, &action2, NULL) == 0) {
            signaled++;
            usleep(500);
        }
        if (!(signaled % 8 == 0 && signaled != 0))
            pause();
    }
    global_binary_change();
}