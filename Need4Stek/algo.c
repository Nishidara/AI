/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-elias.abassi
** File description:
** algo
*/

#include "include/my.h"

int moyenne(int *lidar, int start, int end)
{
    int moyenne = 0;
    int ecart = end - start;
    for (int x = 0; x != ecart; x++) {
        moyenne += lidar[start + x];
    }
    moyenne = moyenne / ecart;
    return moyenne;
}

char *my_getline(void)
{
    char *str = NULL;
    size_t check = 100;
    getline(&str, &check, stdin);
    return str;
}

void get_cspeed(void)
{
    write(1, "GET_CURRENT_SPEED\n", 18);
    char *speed = my_getline();
    write(2, "\n\n", 3); write(2, speed, strlen(speed)); write(2, "\n\n", 3);
}

void algo2(int *lidar)
{
    int moy_left = moyenne(lidar, 0, 5);
    int moy_right = moyenne(lidar, 26, 31);
    int moy_mid = moyenne(lidar, 12, 19);
    int lim_left = lidar[0];
    int lim_right = lidar[31];

    if (moy_left > moy_right && moy_mid >= 500 && moy_right >= 100) {
        write(1, "WHEELS_DIR:0.15\n", 16); get_and_display();
        write(1, "CAR_FORWARD:0.5\n", 16); get_and_display();
        write(2, "gauche -\n", 10); return;
    } else if (moy_left > moy_right && moy_mid <= 500) {
        write(1, "WHEELS_DIR:0.4\n", 15); get_and_display();
        write(1, "CAR_FORWARD:0.3\n", 16); get_and_display();
        write(2, "gauche moy\n", 12); return;
    } else if (moy_right <= 500 && !(moy_left <= 500) && moy_mid >= 500) {
        write(1, "WHEELS_DIR:0.8\n", 15); get_and_display();
        write(1, "CAR_FORWARD:0.15\n", 17); get_and_display();
        write(2, "gauche +\n", 10); return;
    }
    algo3(lidar);
}

int algo(int *lidar)
{
    get_cspeed();
    if (moyenne(lidar, 10, 20) <= 100 || moyenne(lidar, 14, 16) <= 30) {
        write(1, "WHEELS_DIR:0\n", 13);
        get_and_display();
        write(1, "CAR_FORWARD:0\n", 14);
        get_and_display();
        write(1, "CAR_BACKWARD:1\n", 15);
        get_and_display();
        return 1;
    }
    if (moyenne(lidar, 12, 18) >= 1000 &&
        moyenne(lidar, 0, 2) >= 75 && moyenne(lidar, 29, 31) >= 75) {
        write(1, "WHEELS_DIR:0\n", 13);
        get_and_display();
        write(1, "CAR_FORWARD:1\n", 14);
        get_and_display();
        return 0;
    }
    algo2(lidar);
    return 0;
}
