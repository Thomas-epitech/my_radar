/*
** EPITECH PROJECT, 2025
** radar
** File description:
** my intlen
*/

int my_intlen(int nb)
{
    int counter = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        nb /= 10;
        counter++;
    }
    return counter;
}
