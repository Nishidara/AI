/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-elias.abassi
** File description:
** clean_lidar
*/

#include "include/my.h"

void free_table(char **table)
{
    for (int x = 0; table[x] != NULL; x++) {
        free(table[x]);
    }
    free(table);
}

int nb_lines_table(char **table)
{
    int count = 0;
    while (table[count] != NULL) {
        count++;
    }
    return count;
}

char **clean_info_lidar(char **info_lidar)
{
    int new_pos = 0;
    char **clean_lidar = malloc(sizeof(char *) * 33);
    for (int x = 0; x != 32; x++) {
        clean_lidar[x] = malloc(sizeof(char) * 7);
    }
    for (int x = 3; x != 35; x++) {
        clean_lidar[new_pos] = info_lidar[x];
        new_pos++;
    }
    clean_lidar[new_pos] = NULL;
    return clean_lidar;
}

void algo3(int *lidar)
{
    int moy_left = moyenne(lidar, 0, 5);
    int moy_right = moyenne(lidar, 26, 31);
    int moy_mid = moyenne(lidar, 12, 19);
    int lim_left = lidar[0];
    int lim_right = lidar[31];

    if (moy_left < moy_right && moy_mid >= 500 && moy_left >= 100) {
        write(1, "WHEELS_DIR:-0.15\n", 17); get_and_display();
        write(1, "CAR_FORWARD:0.5\n", 16); get_and_display();
        write(2, "droite -\n", 10); return;
    } else if (moy_left < moy_right && moy_mid <= 500) {
        write(1, "WHEELS_DIR:-0.4\n", 16); get_and_display();
        write(1, "CAR_FORWARD:0.3\n", 16); get_and_display();
        write(2, "droite moy\n", 12); return;
    } else if (moy_left <= 500 && !(moy_right <= 500) && moy_mid >= 500) {
        write(1, "WHEELS_DIR:-0.8\n", 16); get_and_display();
        write(1, "CAR_FORWARD:0.15\n", 17); get_and_display();
        write(2, "droite +\n", 10); return;
    }
}
