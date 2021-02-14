/*
** EPITECH PROJECT, 2020
** connections signals
** File description:
** connections
*/

#include "../include/signal.h"
#include "../include/my.h"

extern st_global *global;

void catch_sig(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;
    write(1, "\nenemy connected\n", 17);
    global->stop = 1;
    global->pid_enemy = info->si_pid;
    global->connected = 1;
    return ;
}

void connected(char *pid_enemy)
{
    write(1, "\nsuccessfully connected\n", 24);
    game_start(my_getnbr(pid_enemy), 2);
}

void connection_p2(char *pid_to_connect, char *path)
{
    (void)path;
    int connect = 0;

    write(1, "my_pid: ", 8);
    my_put_nbr(getpid());
    connect = kill(my_getnbr(pid_to_connect), SIGUSR2);
    my_putstr(pid_to_connect);
    if (connect == 0){
        write(1, "\nsuccessfully connected\n", 24);
        game_start(my_getnbr(pid_to_connect), 2);
    }
    else {
        write(1, "\nConnection error\n", 18);
        exit(84);
    }
}

void connection_p1(char *path)
{
    struct sigaction act;
    (void)path;

    write(1, "my_pid: ", 8);
    my_put_nbr(getpid());
    act.sa_sigaction = &catch_sig;
    act.sa_flags = SA_SIGINFO;
    write(1, "\nwaiting for enemy connection...\n", 33);
    sigaction(SIGUSR2, &act, NULL);
    if (global->connected == 0)
        pause();
    if (global->connected == 1)
        game_start(global->pid_enemy, 1);
    while (global->connected == 1)
        usleep(100);
}