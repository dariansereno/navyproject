/*
** EPITECH PROJECT, 2020
** my find prime supp
** File description:
** function which finds the next prime number
*/

int my_find_prime_sup(int nb)
{
    int i = 2;

    while (i < nb) {
        if (nb % i == 0) {
            nb++;
            i = 2;
        }
        i++;
    }
    return (nb);
}
