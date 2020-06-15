/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Write a function that returns a number, sent to the function as a string
*/

#include <stdio.h>

double my_getnbr(char const *str)
{
    double res = 0;
    double decimal_part = 0;
    int is_neg = 1;

    if (*str == '-') {
        is_neg = -1;
        *str++;
    }
    while (*str && '0' <= *str && *str <= '9') {
        res *= 10;
        res += *str++ - 48;
    }
    if (*str++) {
        decimal_part = my_getnbr(str);
        while (decimal_part > 0)
            decimal_part = decimal_part/10;
        res += decimal_part;
    }
    res *= is_neg;
    printf("nbr = %f\n", res);
    return (res);
}