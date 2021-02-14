/*
** EPITECH PROJECT, 2020
** header
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

typedef struct global_t {
    int i;
    char *sig;
    char *sig_attack;
    char *binary;
    int attack;
    bool touched;
    int pid_enemy;
    int stop;
    int connected;
} st_global;

typedef struct game_t {
    int player;
    int turn;
    size_t size;
    int pid_enemy;
    int ship_left_p1;
    int ship_left_p2;
    char *attack;
}st_game;

//Player One Start Handling
void player_one_first_attack(char *attack, size_t size, int pid_enemy);
int player_one_first_attack_is_touched(int ship_left_p2);
int player_one_first_attack_receive(int ship_left_p1);
int player_one_first_attack_display(int turn);
void player_one_first_attack_handling(st_game *game);
int good_attack(char *attack);

void player_one_attack(st_game *game);
void player_one_receive(st_game *game);
void player_one_display(void);
void player_one_handling(st_game *game);

void player_two_receive(st_game *game);
void player_two_attack(st_game *game);
void player_two_display(void);
void player_two_handling(st_game *game);

//Player Two Start Handling
void player_two_first_attack_receive(st_game *game);
void player_two_first_attack(st_game *game);
int player_two_first_attack_display(int turn);
void player_two_first_attack_handling(st_game *game);

int convert_column_attack(char c, int column);
int convert_line_attack(char c, int line);
void line_attack(char *line_str, int pid_enemy);
void column_attack(char *column_str, int pid_enemy);
char return_letter(int line);
void signal_start(int sig, siginfo_t *sig_info, void *data);
int signal_connect(void);
char **split_my_binary(char *signal);
void reinitalize_global(void);
int receive_convert(char *signal);
void connection_p1(char *path);
void connection_p2(char *pid_to_connect, char *path);
int convert_to_attack_line(char c);
int convert_to_attack_column(char c);
int convert_column_attack2(char c, int column);
int convert_line_attack2(char c, int line);
int convert_to_attack(char *str, int pid_enemy);
int convert_in_decimal(char *nb, char *base);
void connected(char *pid_enemy);
int signal_number(int sig);
void signals_line(void);
void global_binary_change();
int signals_column(void);
void game_start(int pid_enemy, int player);
void openfile_hit(char *path, bool hit, int index);
char *openfile_show(char *path, int index, char length);
char *changed_map_hit(char *map, bool hit, int index);
char *changed_map_show(char *map, int index, char length);
int where_hitted_letter(char c, int x);
int where_hitted_nb(int x, int index);
int where_are_boat(char c, int x);
void recover_position(char **map);
void open_position(char *path);
void check_file2(char **map);
void check_file(char **map);
char *recover_position2(char **map);
void recover_position_p2(char **map);
char *recover_position2_p2(char **map);
void open_position_p2(char *path);
void open_first_round(char *path);
void reset_maps(void);
void reset_openfile(char *path);
char *reset_change(void);
bool check_boats(char *map);
bool hit_or_not(int index, char *path);
void openfile2_hit(char *path, bool hit, int index);

int convert_in_decimal(char *nb, char *base);
int final_len_converted(int nb, int base_length);
char *fill_with_zero(char *converted, int i, int final_size);
char *convert_to_base(int nb, char *base);
int where_in_base(char nb, char *base);
int is_in_base(char c, char *base);
void base_check(char *str, char *base);
int base_size(char *str);

char *convert_to_base(int nb, char *base);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(const char *str, const char *separator);