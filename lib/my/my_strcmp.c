/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] ^ s2[i])
            return *s1 ? 1 : -1;
        if (s1[i] != s2[i])
            return s1[i] > s2[i] ? 1 : -1;
        i++;
    }
    return 0;
}
