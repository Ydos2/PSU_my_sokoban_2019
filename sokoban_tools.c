/*
** EPITECH PROJECT, 2019
** sokoban_tools
** File description:
** sokoban_tools
*/

#include "include/frambuffer.h"
#include "include/my.h"

int set_end_game(player_t *player)
{
    if (player->win == 1)
        return (0);
    else if (player->win == 2)
        return (1);
    return (1);
}

int define_caracter(map_t *map_struct)
{
    map_struct->result = 0;
    for (int i = 0; map_struct->map[i] != NULL; i++)
        for (int j = 0; map_struct->map[i][j] != '\0'; j++)
            set_caracter(map_struct, i, j);
    if (map_struct->result == 84)
        return (84);
    else
        return (0);
}

void set_caracter(map_t *map_struct, int i, int j)
{
    int a = 0;

    if (map_struct->map[i][j] == 'O')
        a = 1;
    if (map_struct->map[i][j] == 'X')
        a = 1;
    if (map_struct->map[i][j] == 'P')
        a = 1;
    if (map_struct->map[i][j] == '#')
        a = 1;
    if (map_struct->map[i][j] == '\n')
        a = 1;
    if (map_struct->map[i][j] == ' ')
        a = 1;
    if (a == 0)
        map_struct->result = 84;
}

void get_defeat(map_t *map_struct, player_t *player,
    int x_position, int y_position)
{
    int nbr_def_x = 0;
    int nbr_def_y = 0;

    if (map_struct->map[y_position+1][x_position] == '#')
        nbr_def_y++;
    if (map_struct->map[y_position-1][x_position] == '#')
        nbr_def_y++;
    if (map_struct->map[y_position][x_position+1] == '#')
        nbr_def_x++;
    if (map_struct->map[y_position][x_position-1] == '#')
        nbr_def_x++;
    if (nbr_def_x >= 1 && nbr_def_y >= 1)
        player->win = 2;
}

int set_loop(map_t *map_struct, player_t *player, char **argv)
{
    int row, col;
    getmaxyx (stdscr, row, col);

    start_map(argv, map_struct);
    if (define_caracter(map_struct) == 84 ||
        row <= map_struct->k-2 || col <= map_struct->i-2) {
        close_param(map_struct, player);
        return (84);
    }
    update_game(map_struct, player, argv);
    close_param(map_struct, player);
}