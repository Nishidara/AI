/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-elias.abassi
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <stdbool.h>

    char **parse_lidar(char *str);
    char *get_lidar(void);
    int value_count(char *str);
    void display_lidar_info(char **table);
    char **clean_info_lidar(char **info_lidar);
    int *int_lidar(char **table);
    int algo(int *lidar);
    void get_and_display(void);
    void algo3(int *lidar);
    int moyenne(int *lidar, int start, int end);

#endif /* !MY_H_ */
