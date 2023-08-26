/*
** EPITECH PROJECT, 2023
** B-AIA-200-LYN-2-1-n4s-elias.abassi
** File description:
** main
*/

#include "include/my.h"
#include <stdint.h>

extern __inline__ uint64_t rdtsc(void) {
  uint64_t a, d;
  __asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));
  return (d<<32) | a;
}

void get_and_display(void)
{
    char *argv_in_str = NULL;
    size_t check = 100;
    getline(&argv_in_str, &check, stdin);
    write(2, argv_in_str, strlen(argv_in_str));
}

int *get_info_lidar(void)
{
    write(1, "GET_INFO_LIDAR\n", 15);
    char *str = get_lidar();
    write(2, str, strlen(str));
    char **info_lidar = parse_lidar(str);
    int *lidar = int_lidar(info_lidar);
    return lidar;
}

int main(void)
{
    write(1, "START_SIMULATION\n", 17);
    get_and_display();
    write(1, "CAR_FORWARD:0.5\n", 16);
    get_and_display();
    long long x = rdtsc();
    while (1) {
        int *lidar = get_info_lidar();
        if (algo(lidar) == 1) {
            write(1, "STOP_SIMULATION\n", 16);
            get_and_display();
            break;
        }
    }
    long long y = rdtsc();
    return 0;
}
