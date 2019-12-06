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
        endwin();
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int row, col;
    map_t *map_struct = NULL;
    player_t *player = NULL;
    init_ncurses();
    getmaxyx (stdscr, row, col);

    if (verif_error(argc, argv) == 1)
        return (0);
    map_struct = malloc(sizeof(map_t));
    player = malloc(sizeof(player_t));
    start_map(argv, map_struct);
    if ((define_caracter(map_struct)) == 84 ||
        row <= map_struct->k-2 || col <= map_struct->i-2) {
        endwin();
        return (84);
    }
    update_game(map_struct, player, argv);
    close_param(map_struct);
    set_end_game(player);
}

void close_param(map_t *map_struct)
{
    free(map_struct->map);
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