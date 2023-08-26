/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-elias.abassi
** File description:
** parse_lidar
*/

#include "include/my.h"

int value_count(char *str)
{
    int count = 0;
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == ':') {
            count++;
        }
    }
    return count + 2;
}

char *get_lidar(void)
{
    char *lidar_info = NULL;
    size_t check = 100;
    getline(&lidar_info, &check, stdin);
    return lidar_info;
}

char **parse_lidar(char *str)
{
    char *token = NULL;
    char **values = malloc(sizeof(char *) * 36);
    for (int x = 0; x != 36; x++) {
        values[x] = malloc(sizeof(char) * strlen(str));
    }
    if (!values) {
        return NULL;
    }
    for (int y = 0; (token = strtok_r(str, ":", &str)); y++) {
        values[y] = token;
        values[y][strlen(token)] = '\0';
    }
    values[36] = NULL;
    values = clean_info_lidar(values);
    return values;
}

void display_lidar_info(char **table)
{
    for (int x = 0; table[x] != NULL; x++) {
        write(2, table[x], strlen(table[x]));
        write(2, "\n", 2);
    }
}

int *int_lidar(char **table)
{
    int nb_values = 0;
    while (table[nb_values] != NULL) {
        nb_values++;
    }
    int *lidar = malloc(sizeof(int) * nb_values + 1);
    for (int x = 0; x != nb_values; x++) {
        lidar[x] = atoi(table[x]);
    }
    lidar[nb_values] = '\0';
    return lidar;
}
