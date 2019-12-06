/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban
*/

#include "include/frambuffer.h"
#include "include/my.h"

void init_ncurses(void)
{
    initscr();
    nodelay(stdscr, TRUE);
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    curs_set(0);
}

int verif_error(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    map_t *map_struct = NULL;
    player_t *player = NULL;

    if (argc != 2)
        return (84);
    if (verif_error(argc, argv) == 1)
        return (0);
    init_ncurses();
    map_struct = malloc(sizeof(map_t));
    player = malloc(sizeof(player_t));
    if (set_loop(map_struct, player, argv) == 84)
        return (84);
    if (set_end_game(player) == 1)
        return (1);
    return (0);
}

void close_param(map_t *map_struct, player_t *player)
{
    free(map_struct->map);
    free(map_struct);
    free(player);
    getch();
    endwin();
}

void help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./my_sokoban map\n", 19);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tmap file representing the warehouse ", 37);
    write(1, "map, containing '#' for walls,\n", 31);
    write(1, "\t\t'P' for the player, 'X' for boxes ", 37);
    write(1, "and '0' for storage locations.\n", 31);
}